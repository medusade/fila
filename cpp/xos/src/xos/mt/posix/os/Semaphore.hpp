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
///   Date: 9/12/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_POSIX_OS_SEMAPHORE_HPP
#define _XOS_MT_POSIX_OS_SEMAPHORE_HPP

#include "xos/mt/os/Semaphore.hpp"

namespace xos {
namespace mt {
namespace posix {
namespace os {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Semaphore: public Base {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Semaphore(unsigned int value): semaphore_(value) {}
    virtual ~Semaphore() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    int sem_post() {
        if ((semaphore_.Release())) {
            return 0;
        }
        return -1;
    }
    virtual int sem_wait() {
        if ((semaphore_.Acquire())) {
            return 0;
        }
        return -1;
    }
    virtual int sem_trywait() {
        AcquireStatus status = AcquireFailed;
        if (AcquireSuccess == (status = semaphore_.TryAcquire())) {
            return 0;
        }
        return -1;
    }
    virtual int sem_timedwait(const struct timespec *abs_timeout) {
        if ((abs_timeout)) {
            int err = 0;
            struct timespec abs_time;

            if (!(err = clock_gettime(CLOCK_REALTIME, &abs_time))) {
                if ((abs_timeout->tv_sec >= abs_time.tv_sec)
                    && (abs_timeout->tv_nsec >= abs_time.tv_nsec)) {
                    AcquireStatus status = AcquireFailed;
                    mseconds_t milliseconds = 0;
                    struct timespec rel_time;

                    rel_time.tv_sec = (abs_timeout->tv_sec - abs_time.tv_sec);
                    rel_time.tv_nsec = (abs_timeout->tv_nsec - abs_time.tv_nsec);
                    milliseconds += seconds_mseconds(rel_time.tv_sec);
                    milliseconds += nseconds_mseconds(rel_time.tv_nsec);
                    if (AcquireSuccess == (status = semaphore_.TimedAcquire(milliseconds))) {
                        return 0;
                    }
                } else {
                    return sem_trywait();
                }
            }
        }
        return -1;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    mt::os::Semaphore semaphore_;
};

} // namespace os
} // namespace posix 
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_POSIX_OS_SEMAPHORE_HPP 
