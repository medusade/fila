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
///   File: Semaphore.hpp
///
/// Author: $author$
///   Date: 9/1/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_POSIX_SEMAPHORE_HPP
#define _XOS_MT_POSIX_SEMAPHORE_HPP

#include "xos/mt/Semaphore.hpp"
#include "xos/logger/Interface.hpp"

#include <semaphore.h>
#include <errno.h>

#if defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )
#if !defined(SEM_HAS_TIMEDWAIT)
#define SEM_HAS_TIMEDWAIT
#endif // !defined(SEM_HAS_TIMEDWAIT)
#endif // defined(_POSIX_TIMEOUTS) && (_POSIX_TIMEOUTS >=0 )

#if !defined(SEM_HAS_TIMEDWAIT)
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
#else // !defined(SEM_HAS_TIMEDWAIT)
#define SEM_HAS_TIMEDWAIT
#endif // !defined(SEM_HAS_TIMEDWAIT)

#define SEMAPHORE_PROCESS_PRIVATE 0
#define SEMAPHORE_PROCESS_SHARED  1

namespace xos {
namespace mt {
namespace posix {

typedef sem_t* SemaphoreTAttachedT;
typedef mt::Semaphore SemaphoreTAttachImplements;
typedef AttachT<SemaphoreTAttachedT, int, 0, AttachException, SemaphoreTAttachImplements> SemaphoreTAttach;
typedef AttachedT<SemaphoreTAttachedT, int, 0, AttachException, SemaphoreTAttach> SemaphoreTAttached;
typedef CreatedT<SemaphoreTAttachedT, int, 0, CreateException, SemaphoreTAttach, SemaphoreTAttached> SemaphoreTCreated;
typedef SemaphoreTAttach SemaphoreTImplements;
typedef SemaphoreTCreated SemaphoreTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: SemaphoreT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = SemaphoreTImplements, class TExtends = SemaphoreTExtends>

class _EXPORT_CLASS SemaphoreT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: SemaphoreT
    ///////////////////////////////////////////////////////////////////////
    SemaphoreT(sem_t* attachedTo, bool isCreated)
    : Extends(attachedTo, isCreated) {
    }
    SemaphoreT(sem_t* attachedTo): Extends(attachedTo) {
    }
    SemaphoreT(size_t initiallyReleased) {
        if (!(this->Create())) {
            CreateException e(CreateFailed);
            throw (e);
        }
    }
    SemaphoreT() {
        if (!(this->Create())) {
            CreateException e(CreateFailed);
            throw (e);
        }
    }
    virtual ~SemaphoreT() {
        if (!(this->Destroyed())) {
            CreateException e(DestroyFailed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(size_t initiallyReleased) {
        sem_t* detached = 0;
        if ((detached = CreateAttached(initiallyReleased))) {
            this->SetIsCreated();
            return detached;
        }
        return false;
    }
    virtual bool Create() {
        return Create(0);
    }
    virtual bool Destroy() {
        sem_t* detached = 0;
        if ((detached = this->Detach())) {
            if ((DestroyDetached(detached))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual sem_t* CreateAttached(size_t initiallyReleased) {
        sem_t* detached = 0;
        if ((this->Destroyed())) {
            if ((detached = CreateDetached(m_sem, initiallyReleased))) {
                this->Attach(detached);
                return detached;
            }
        }
        return 0;
    }
    virtual sem_t* CreateDetached
    (sem_t& sem, size_t initiallyReleased) const {
        int pshared = SEMAPHORE_PROCESS_PRIVATE;
        int err = 0;

        XOS_LOG_DEBUG("::sem_init(&sem, pshared, initiallyReleased)...");
        if ((!(err = ::sem_init(&sem, pshared, initiallyReleased)))) {
            XOS_LOG_DEBUG("...::sem_init(&sem, pshared, initiallyReleased)");
            return &sem;
        } else {
            XOS_LOG_ERROR("...failed err = " << err << " on ::sem_init(&sem, pshared, initiallyReleased)");
        }
        return 0;
    }
    virtual bool DestroyDetached(sem_t* sem) const {
        if ((sem)) {
            int err = 0;

            XOS_LOG_DEBUG("::sem_destroy(sem)...");
            if (!(err = sem_destroy(sem))) {
                XOS_LOG_DEBUG("...::sem_destroy(sem)");
                return true;
            } else {
                XOS_LOG_ERROR("...failed err = " << err << " on ::sem_destroy(sem)");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Acquire() {
        if (AcquireSuccess == (UntimedAcquire())) {
            return true;
        }
        return false;
    }
    virtual bool Release() {
        sem_t* sem = 0;

        if ((sem = this->m_attachedTo)) {
            int err = 0;
            
            XOS_LOG_DEBUG("::sem_post(sem)...");
            if (!(err = ::sem_post(sem))) {
                XOS_LOG_DEBUG("...::sem_post(sem)");
                return true;
            } else {
                XOS_LOG_ERROR("...failed errno = " << errno << " ::on sem_post(sem)");
            }
        }
        return false;
    }
    virtual AcquireStatus TryAcquire() {
        sem_t* sem = 0;
        if ((sem = this->m_attachedTo)) {
            int err = 0;

            XOS_LOG_TRACE("::sem_trywait(sem)...");
            if (!(err = sem_trywait(sem))) {
                XOS_LOG_DEBUG("...::sem_trywait(sem)");
                return AcquireSuccess;
            } else {
                switch (errno) {
                case ETIMEDOUT:
                    XOS_LOG_TRACE("...ETIMEDOUT errno = " << errno << " on ::sem_trywait(sem)");
                    return AcquireBusy;
                case EINTR:
                    XOS_LOG_ERROR("...EINTR errno = " << errno << " on ::sem_trywait(sem)");
                    return AcquireInterrupted;
                default:
                    XOS_LOG_ERROR("...failed errno = " << errno << " on ::sem_trywait(sem)");
                }
            }
        }
        return AcquireFailed;
    }
    virtual AcquireStatus TimedAcquire(mseconds_t milliseconds) {
        if (0 > (milliseconds)) {
            return UntimedAcquire();
        } else {
#if defined(SEM_HAS_TIMEDWAIT)
            sem_t* sem = 0;

            if ((sem = this->m_attachedTo)) {
                int err = 0;
                struct timespec untilTime;

                clock_gettime(CLOCK_REALTIME, &untilTime);
                untilTime.tv_sec +=  mseconds_seconds(milliseconds);
                untilTime.tv_nsec +=  mseconds_nseconds(milliseconds);

                XOS_LOG_TRACE("::sem_timedwait(sem, &untilTime)...");
                if (!(err = ::sem_timedwait(sem, &untilTime))) {
                    XOS_LOG_DEBUG("...::sem_timedwait(sem, &untilTime)");
                    return AcquireSuccess;
                } else {
                    switch (errno) {
                    case ETIMEDOUT:
                        XOS_LOG_TRACE("...ETIMEDOUT errno = " << errno << " on ::sem_timedwait(sem, &untilTime)");
                        return AcquireBusy;
                    case EINTR:
                        XOS_LOG_ERROR("...EINTR errno = " << errno << " on ::sem_timedwait(sem, &untilTime)");
                        return AcquireInterrupted;
                    default:
                        XOS_LOG_ERROR("...failed errno = " << errno << " on ::sem_timedwait(sem, &untilTime)");
                    }
                }
            }
#else // defined(SEM_HAS_TIMEDWAIT)
            XOS_LOG_ERROR("...return AcquireInvalid");
            return AcquireInvalid;
#endif // defined(SEM_HAS_TIMEDWAIT)
        }
        return AcquireFailed;
    }
    virtual AcquireStatus UntimedAcquire() {
        sem_t* sem = 0;
        if ((sem = this->m_attachedTo)) {
            int err = 0;

            XOS_LOG_DEBUG("::sem_wait(sem)...");
            if (!(err = sem_wait(sem))) {
                XOS_LOG_DEBUG("...::sem_wait(sem)");
                return AcquireSuccess;
            } else {
                switch (errno) {
                case ETIMEDOUT:
                    XOS_LOG_ERROR("...ETIMEDOUT errno = " << errno << " on ::sem_wait(sem)");
                    return AcquireBusy;
                case EINTR:
                    XOS_LOG_ERROR("...EINTR errno = " << errno << " on ::sem_wait(sem)");
                    return AcquireInterrupted;
                default:
                    XOS_LOG_ERROR("...failed errno = " << errno << " on ::sem_wait(sem)");
                }
            }
        }
        return AcquireFailed;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    sem_t m_sem;
};
typedef SemaphoreT<> Semaphore;

} // namespace posix 
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_POSIX_SEMAPHORE_HPP 

        

