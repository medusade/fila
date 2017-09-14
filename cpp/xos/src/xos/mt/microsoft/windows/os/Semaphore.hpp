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
#ifndef _XOS_MT_MICROSOFT_WINDOWS_OS_SEMAPHORE_HPP
#define _XOS_MT_MICROSOFT_WINDOWS_OS_SEMAPHORE_HPP

#include "xos/mt/os/Semaphore.hpp"

namespace xos {
namespace mt {
namespace microsoft {
namespace windows {
namespace os {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Semaphore: public platform::microsoft::windows::Handle {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Semaphore() {}
    virtual ~Semaphore() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual BOOL CloseHandle() {
        BOOL success = FALSE;
        if ((semaphore_.Destroyed())) {
            success = TRUE;
        }
        return success;
    }
    virtual BOOL ReleaseSemaphore(LONG lReleaseCount, LPLONG lpPreviousCount) {
        BOOL success = FALSE;
        if ((0 < lReleaseCount) && (2 > lReleaseCount)) {
            if ((semaphore_.Release())) {
                success = TRUE;
            }
        }
        return success;
    }
    virtual DWORD WaitForSingleObject(DWORD dwMilliseconds) {
        DWORD dwStatus = WAIT_FAILED;
        AcquireStatus status = ::xos::AcquireFailed;

        if (INFINITE != dwMilliseconds) {
            status = semaphore_.TimedAcquire(dwMilliseconds);
        } else {
            status = semaphore_.UntimedAcquire();
        }
        switch (status) {
        case AcquireSuccess:
            dwStatus = WAIT_OBJECT_0;
            break;
        case AcquireBusy:
            dwStatus = WAIT_TIMEOUT;
            break;
        case AcquireInterrupted:
            dwStatus = WAIT_ABANDONED;
            break;
        }
        return dwStatus;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    mt::os::Semaphore semaphore_;
};

} // namespace os
} // namespace windows 
} // namespace microsoft 
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_MICROSOFT_WINDOWS_OS_SEMAPHORE_HPP 
