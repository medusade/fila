///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: mutex.hpp
///
/// Author: $author$
///   Date: 9/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_POSIX_MUTEX_HPP
#define _XOS_MT_POSIX_MUTEX_HPP

#include "xos/mt/mutex.hpp"
#include "xos/base/created.hpp"
#include "xos/logger/interface.hpp"

#include <pthread.h>
#include <time.h>
#include <errno.h>

#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0)
#if !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#define PTHREAD_MUTEX_HAS_TIMEDLOCK
#endif // !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#endif // defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0)

#if !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#if !defined(CLOCK_REALTIME)
#define CLOCK_REALTIME 0
#define clockid_t int
inline int clock_gettime
(clockid_t clk_id, struct timespec *res) {
    if ((res)) {
        memset(res, 0, sizeof(struct timespec));
        return 0; }
    return 1; }
inline int pthread_mutex_timedlock
(pthread_mutex_t *mutex, const struct timespec *abs_timeout) {
    return 1; }
#else // !defined(CLOCK_REALTIME)
#endif // !defined(CLOCK_REALTIME)
#define PTHREAD_MUTEX_HAS_TIMEDLOCK
#else // !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
#endif // !defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)

namespace xos {
namespace mt {
namespace posix {

typedef pthread_mutex_t* mutext_attached_t;
typedef mt::mutex mutext_attach_implements;
typedef attacht<mutext_attached_t, int, 0, attach_exception, mutext_attach_implements> mutext_attach;
typedef attachedt<mutext_attached_t, int, 0, attach_exception, mutext_attach> mutext_attached;
typedef createdt<mutext_attached_t, int, 0, create_exception, mutext_attach, mutext_attached> mutext_created;
typedef mutext_attach mutext_implements;
typedef mutext_created mutext_extends;
///////////////////////////////////////////////////////////////////////
///  class: mutext
///////////////////////////////////////////////////////////////////////
template
<class TImplements = mutext_implements, class TExtends = mutext_extends>

class _EXPORT_CLASS mutext: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    mutext(pthread_mutex_t* attached_to, bool is_created)
    : extends(attached_to, is_created) {
    }
    mutext(pthread_mutex_t* attached_to): extends(attached_to) {
    }
    mutext(bool initally_locked) {
        if (!(this->create(initally_locked))) {
            create_exception e(create_failed);
            throw (e);
        }
    }
    mutext() {
        if (!(this->create())) {
            create_exception e(create_failed);
            throw (e);
        }
    }
    virtual ~mutext() {
        if (!(this->destroyed())) {
            create_exception e(destroy_failed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create(bool initally_locked) {
        if (!(initally_locked)) {
            return this->create();
        }
        return false;
    }
    virtual bool create() {
        pthread_mutex_t* detached = 0;
        if ((detached = create_attached())) {
            this->set_is_created();
            return detached;
        }
        return false;
    }
    virtual bool destroy() {
        pthread_mutex_t* detached = 0;
        if ((detached = this->detach())) {
            if ((destroy_detached(detached))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual pthread_mutex_t* create_attached() {
        pthread_mutex_t* detached = 0;
        if ((this->destroyed())) {
            if ((detached = create_detached(m_mutexattr, m_mutex))) {
                this->attach(detached);
                return detached;
            }
        }
        return 0;
    }
    virtual pthread_mutex_t* create_detached
    (pthread_mutexattr_t& mutexattr, pthread_mutex_t& mutex) const {
        int err = 0;

        XOS_IF_LOG_DEBUG("pthread_mutexattr_init(&mutexattr)...");
        if (!(err = pthread_mutexattr_init(&mutexattr))) {

            XOS_IF_LOG_DEBUG("pthread_mutex_init(&mutex, &mutexattr)...");
            if (!(err = pthread_mutex_init(&mutex, &mutexattr))) {

                XOS_IF_LOG_DEBUG("pthread_mutexattr_destroy(&mutexattr)...");
                if ((err = pthread_mutexattr_destroy(&mutexattr))) {
                    if ((err = pthread_mutex_destroy(&mutex))) {
                    }
                    return 0;
                }
                return &mutex;
            }
            if ((err = pthread_mutexattr_destroy(&mutexattr))) {
            }
        }
        return 0;
    }
    virtual bool destroy_detached(pthread_mutex_t* mutex) const {
        if ((mutex)) {
            int err = 0;
            XOS_IF_LOG_DEBUG("pthread_mutex_destroy(mutex)...");
            if (!(err = pthread_mutex_destroy(mutex))) {
                return true;
            } else {
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool lock() {
        pthread_mutex_t* mutex = 0;
        int err = 0;
        if ((mutex = this->m_attached_to)) {
            XOS_IF_LOG_DEBUG("pthread_mutex_lock(mutex)...")
            if (!(err = pthread_mutex_lock(mutex))) {
                return true;
            } else {
            }
        }
        return false;
    }
    virtual bool unlock() {
        pthread_mutex_t* mutex = 0;
        int err = 0;
        if ((mutex = this->m_attached_to)) {
            XOS_IF_LOG_DEBUG("pthread_mutex_unlock(mutex)...")
            if (!(err = pthread_mutex_unlock(mutex))) {
                return true;
            } else {
            }
        }
        return false;
    }
    virtual lock_status try_lock() {
        pthread_mutex_t* mutex = 0;
        if ((mutex = this->m_attached_to)) {
            int err = 0;
            XOS_IF_LOG_TRACE("pthread_mutex_trylock(mutex)...");
            if ((err =  pthread_mutex_trylock(mutex))) {
                switch(err) {
                case ETIMEDOUT:
                    XOS_IF_LOG_TRACE("...ETIMEDOUT err = "<< err << " on pthread_mutex_trylock(mutex)")
                    return lock_busy;
                case EINTR:
                    XOS_IF_LOG_ERROR("...EINTR err = "<< err << " on pthread_mutex_trylock(mutex)")
                    return lock_interrupted;
                default:
                    XOS_IF_LOG_ERROR("...failed err = "<< err << " on pthread_mutex_trylock(mutex)")
                    return lock_failed;
                }
            } else {
                return lock_success;
            }
        }
        return lock_failed;
    }
    virtual lock_status timed_lock(mseconds_t milliseconds) {
        if (0 < (milliseconds)) {
#if defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
            pthread_mutex_t* mutex = 0;
            if ((mutex = this->m_attached_to)) {
                int err = 0;
                struct timespec until_time;
                clock_gettime(CLOCK_REALTIME, &until_time);
                until_time.tv_sec +=  mseconds_seconds(milliseconds);
                until_time.tv_nsec +=  mseconds_nseconds(milliseconds);

                XOS_IF_LOG_TRACE("pthread_mutex_timedlock(mutex, &until_time)...");
                if ((err = pthread_mutex_timedlock(mutex, &until_time))) {
                    switch(err) {
                    case ETIMEDOUT:
                        XOS_IF_LOG_TRACE("...ETIMEDOUT err = "<< err << " on pthread_mutex_timedlock(mutex, &until_time)")
                        return lock_busy;
                    case EINTR:
                        XOS_IF_LOG_ERROR("...EINTR err = "<< err << " on pthread_mutex_timedlock(mutex, &until_time)")
                        return lock_interrupted;
                    default:
                        XOS_IF_LOG_ERROR("...failed err = "<< err << " on pthread_mutex_timedlock(mutex, &until_time)")
                        return lock_failed;
                    }
                } else {
                    return lock_success;
                }
            }
#else // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
            XOS_IF_LOG_ERROR("...invalid on pthread_mutex_timedlock(mutex, &until_time)")
            return lock_invalid;
#endif // defined(PTHREAD_MUTEX_HAS_TIMEDLOCK)
        } else {
            if (0 > (milliseconds)) {
                return untimed_lock();
            } else {
                return try_lock();
            }
        }
        return lock_failed;
    }
    virtual lock_status untimed_lock() {
        pthread_mutex_t* mutex = 0;
        if ((mutex = this->m_attached_to)) {
            int err = 0;
            XOS_IF_LOG_DEBUG("pthread_mutex_lock(mutex)...")
            if ((err =  pthread_mutex_lock(mutex))) {
                switch(err) {
                case ETIMEDOUT:
                    XOS_IF_LOG_ERROR("...ETIMEDOUT err = "<< err << " on pthread_mutex_lock(mutex)")
                    return lock_busy;
                case EINTR:
                    XOS_IF_LOG_ERROR("...EINTR err = "<< err << " on pthread_mutex_lock(mutex)")
                    return lock_interrupted;
                default:
                    XOS_IF_LOG_ERROR("...failed err = "<< err << " on pthread_mutex_lock(mutex)")
                    return lock_failed;
                }
            } else {
                return lock_success;
            }
        }
        return lock_failed;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    pthread_mutexattr_t m_mutexattr;
    pthread_mutex_t m_mutex;
};
typedef mutext<> mutex;

namespace logger {
typedef loggedt<false> mutext_logged;
typedef mt::mutext<mutext_logged> mutext_attach_implements;
typedef attacht<mutext_attached_t, int, 0, attach_exception, mutext_attach_implements> mutext_attach;
typedef attachedt<mutext_attached_t, int, 0, attach_exception, mutext_attach> mutext_attached;
typedef createdt<mutext_attached_t, int, 0, create_exception, mutext_attach, mutext_attached> mutex_tCreated;
typedef mutext_attach mutex_tImplements;
typedef mutex_tCreated mutex_tExtends;
typedef mutext<mutex_tImplements, mutex_tExtends> mutex;
} // namespace logger

} // namespace posix
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_POSIX_MUTEX_HPP 
