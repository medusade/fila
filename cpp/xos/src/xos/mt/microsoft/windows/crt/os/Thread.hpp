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
///   File: Thread.hpp
///
/// Author: $author$
///   Date: 9/12/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_MICROSOFT_WINDOWS_CRT_OS_THREAD_HPP
#define _XOS_MT_MICROSOFT_WINDOWS_CRT_OS_THREAD_HPP

#include "xos/mt/os/Thread.hpp"

namespace xos {
namespace mt {
namespace microsoft {
namespace windows {
namespace crt {
namespace os {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Thread: public platform::microsoft::windows::Handle {
public:
    typedef unsigned ( __stdcall *start_address_t )( void * );
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Thread
    (bool initiallySuspended,
     start_address_t startAddress, void* parameter)
    : ran_(startAddress, parameter), thread_(initiallySuspended, ran_) {
    }
    Thread
    (bool initiallySuspended,
     start_address_t startAddress)
    : ran_(startAddress), thread_(initiallySuspended, ran_) {
    }
    Thread
    (start_address_t startAddress, void* parameter)
    : ran_(startAddress, parameter), thread_(ran_) {
    }
    Thread
    (start_address_t startAddress)
    : ran_(startAddress), thread_(ran_) {
    }
    Thread(bool initiallySuspended): thread_(initiallySuspended, ran_) {
    }
    Thread(): thread_(ran_) {
    }
    virtual ~Thread() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual BOOL CloseHandle() {
        BOOL success = FALSE;
        if ((thread_.Destroyed())) {
            success = TRUE;
        }
        return success;
    }
    virtual DWORD WaitForSingleObject(DWORD dwMilliseconds) {
        DWORD dwStatus = WAIT_FAILED;
        JoinStatus status = ::xos::JoinFailed;

        if (INFINITE != dwMilliseconds) {
            status = thread_.TimedJoin(dwMilliseconds);
        } else {
            status = thread_.UntimedJoin();
        }
        switch (status) {
        case JoinSuccess:
            dwStatus = WAIT_OBJECT_0;
            break;
        case JoinBusy:
            dwStatus = WAIT_TIMEOUT;
            break;
        case JoinInterrupted:
            dwStatus = WAIT_ABANDONED;
            break;
        }
        return dwStatus;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Ran: virtual public xos::Ran {
    public:
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        Ran(start_address_t startAddress, void* parameter)
        : m_startAddress(startAddress), m_parameter(parameter) {
        }
        Ran(start_address_t startAddress)
        : m_startAddress(startAddress), m_parameter(0) {
        }
        Ran(): m_startAddress(0), m_parameter(0) {
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
        virtual void Run() {
            if ((m_startAddress)) {
                m_startAddress(m_parameter);
            }
        }
        ///////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////
    protected:
        start_address_t m_startAddress;
        void* m_parameter;
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Ran ran_;
    mt::os::Thread thread_;
};

} // namespace os
} // namespace crt 
} // namespace windows 
} // namespace microsoft 
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_MICROSOFT_WINDOWS_CRT_OS_THREAD_HPP 
