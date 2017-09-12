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
///   File: semaphore.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_APPLE_MACH_SEMAPHORE_HPP
#define _XOS_MT_APPLE_MACH_SEMAPHORE_HPP

#include "xos/mt/semaphore.hpp"
#include "xos/logger/interface.hpp"

#include <mach/task.h>
#include <mach/mach.h>
#include <mach/semaphore.h>

namespace xos {
namespace mt {
namespace apple {
namespace mach {

typedef semaphore_t* semaphoret_attached_t;
typedef mt::semaphore semaphoret_attach_implements;
typedef attacht<semaphoret_attached_t, int, 0, attach_exception, semaphoret_attach_implements> semaphoret_attach;
typedef attachedt<semaphoret_attached_t, int, 0, attach_exception, semaphoret_attach> semaphoret_attached;
typedef createdt<semaphoret_attached_t, int, 0, create_exception, semaphoret_attach, semaphoret_attached> semaphoret_created;
typedef semaphoret_attach semaphoret_implements;
typedef semaphoret_created semaphoret_extends;
///////////////////////////////////////////////////////////////////////
///  class: semaphoret
///////////////////////////////////////////////////////////////////////
template
<class TImplements = semaphoret_implements, class TExtends = semaphoret_extends>

class _EXPORT_CLASS semaphoret: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    semaphoret(semaphore_t* attached_to, bool is_created)
    : extends(attached_to, is_created) {
    }
    semaphoret(semaphore_t* attached_to): extends(attached_to) {
    }
    semaphoret(size_t initially_released) {
        if (!(this->create(initially_released))) {
            create_exception e(create_failed);
            throw (e);
        }
    }
    semaphoret() {
        if (!(this->create())) {
            create_exception e(create_failed);
            throw (e);
        }
    }
    virtual ~semaphoret() {
        if (!(this->destroyed())) {
            create_exception e(destroy_failed);
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool create(size_t initially_released) {
        semaphore_t* detached = 0;

        if ((detached = create_attached(initially_released))) {
            this->set_is_created();
            return detached;
        }
        return false;
    }
    virtual bool create() {
        return create(0);
    }
    virtual bool destroy() {
        semaphore_t* detached = 0;

        if ((detached = this->detach())) {
            if ((destroy_detached(detached))) {
                return true;
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual semaphore_t* create_attached(size_t initially_released) {
        semaphore_t* detached = 0;

        if ((this->destroyed())) {
            if ((detached = create_detached(m_semaphore, initially_released))) {
                this->attach(detached);
                return detached;
            }
        }
        return 0;
    }
    virtual semaphore_t* create_detached
    (semaphore_t& semaphore, size_t initially_released) const {
        int err = 0;
        task_t task = mach_task_self();
        sync_policy_t sync_policy = SYNC_POLICY_FIFO;

        XOS_LOG_DEBUG("::semaphore_create(task, &semaphore, sync_policy, initially_released)...");
        if (KERN_SUCCESS == (err = ::semaphore_create(task, &semaphore, sync_policy, initially_released))) {
            return &semaphore;
        } else {
            XOS_LOG_ERROR("...failed err = " << err << " on ::semaphore_create(task, &semaphore, sync_policy, initially_released)");
        }
        return 0;
    }
    virtual bool destroy_detached(semaphore_t* semaphore) const {
        if ((semaphore)) {
            int err = 0;
            task_t task = mach_task_self();

            XOS_LOG_DEBUG("::semaphore_destroy(task, *semaphore)...")
            if (KERN_SUCCESS == (err = ::semaphore_destroy(task, *semaphore))) {
                return true;
            } else {
                XOS_LOG_ERROR("...failed err = " << err << " on ::semaphore_destroy(task, *semaphore)");
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool acquire() {
        if (acquire_success == (untimed_acquire())) {
            return true;
        }
        return false;
    }
    virtual bool release() {
        semaphore_t* semaphore = 0;

        if ((semaphore = this->m_attached_to)) {
            int err = 0;

            XOS_LOG_DEBUG("::semaphore_signal(*semaphore)...");
            if (KERN_SUCCESS == (err = ::semaphore_signal(*semaphore))) {
                return true;
            } else {
                XOS_LOG_ERROR("...failed err = " << err << " on ::semaphore_signal(*semaphore)");
            }
        }
        return false;
    }
    virtual acquire_status try_acquire() {
        return timed_acquire(0);
    }
    virtual acquire_status timed_acquire(mseconds_t milliseconds) {
        if (0 > (milliseconds)) {
            return untimed_acquire();
        } else {
            semaphore_t* semaphore = 0;

            if ((semaphore = this->m_attached_to)) {
                int err = 0;
                mach_timespec_t wait_time;
                wait_time.tv_sec = mseconds_seconds(milliseconds);
                wait_time.tv_nsec = mseconds_nseconds(milliseconds);

                XOS_LOG_TRACE("::semaphore_timedwait(*semaphore, wait_time)...");
                if (KERN_SUCCESS == (err = ::semaphore_timedwait(*semaphore, wait_time))) {
                    return acquire_success;
                } else {
                    if (KERN_OPERATION_TIMED_OUT == (err)) {
                        XOS_LOG_TRACE("...failed err = KERN_OPERATION_TIMED_OUT on ::semaphore_timedwait(*semaphore, wait_time)");
                        return acquire_busy;
                    } else {
                        if (KERN_ABORTED == (err)) {
                            XOS_LOG_ERROR("...failed err = KERN_ABORTED on ::semaphore_timedwait(*semaphore, wait_time)");
                            return acquire_interrupted;
                        } else {
                            XOS_LOG_ERROR("...failed err = " << err << " on ::semaphore_timedwait(*semaphore, wait_time)");
                        }
                    }
                }
            }
        }
        return acquire_failed;
    }
    virtual acquire_status untimed_acquire() {
        semaphore_t* semaphore = 0;

        if ((semaphore = this->m_attached_to)) {
            int err = 0;

            XOS_LOG_DEBUG("::semaphore_wait(*semaphore)...");
            if (KERN_SUCCESS == (err = ::semaphore_wait(*semaphore))) {
                return acquire_success;
            } else {
                if (KERN_OPERATION_TIMED_OUT == (err)) {
                    XOS_LOG_ERROR("...failed err = KERN_OPERATION_TIMED_OUT on ::semaphore_wait(*semaphore)");
                    return acquire_busy;
                } else {
                    if (KERN_ABORTED == (err)) {
                        XOS_LOG_ERROR("...failed err = KERN_ABORTED on ::semaphore_wait(*semaphore)");
                        return acquire_interrupted;
                    } else {
                        XOS_LOG_ERROR("...failed err = " << err << " on ::semaphore_wait(*semaphore)");
                    }
                }
            }
        }
        return acquire_failed;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    semaphore_t m_semaphore;
};
typedef semaphoret<> semaphore;

} // namespace mach
} // namespace apple 
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_APPLE_MACH_SEMAPHORE_HPP 
