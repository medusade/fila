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
///   File: Mutex.hpp
///
/// Author: $author$
///   Date: 9/11/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_MICROSOFT_WINDOWS_OS_MUTEX_HPP
#define _XOS_MT_MICROSOFT_WINDOWS_OS_MUTEX_HPP

#include "xos/mt/os/Mutex.hpp"

namespace xos {
namespace mt {
namespace microsoft {
namespace windows {
namespace os {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Mutex: public platform::microsoft::windows::Handle {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Mutex() {}
    virtual ~Mutex() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual BOOL CloseHandle() {
        BOOL success = FALSE;
        if ((mutex_.Destroyed())) {
            success = TRUE;
        }
        return success;
    }
    virtual BOOL ReleaseMutex() {
        BOOL success = FALSE;
        if ((mutex_.Unlock())) {
            success = TRUE;
        }
        return success;
    }
    virtual DWORD WaitForSingleObject(DWORD dwMilliseconds) {
        DWORD dwStatus = WAIT_FAILED;
        LockStatus status = ::xos::LockFailed;

        if (INFINITE != dwMilliseconds) {
            status = mutex_.TimedLock(dwMilliseconds);
        } else {
            status = mutex_.UntimedLock();
        }
        switch (status) {
        case LockSuccess:
            dwStatus = WAIT_OBJECT_0;
            break;
        case LockBusy:
            dwStatus = WAIT_TIMEOUT;
            break;
        case LockInterrupted:
            dwStatus = WAIT_ABANDONED;
            break;
        }
        return dwStatus;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    mt::os::Mutex mutex_;
};

} // namespace os
} // namespace windows 
} // namespace microsoft 
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_MICROSOFT_WINDOWS_OS_MUTEX_HPP 
