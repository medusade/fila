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
#ifndef _XOS_MT_MICROSOFT_WINDOWS_MUTEX_HPP
#define _XOS_MT_MICROSOFT_WINDOWS_MUTEX_HPP

#include "xos/mt/Mutex.hpp"
#include "xos/base/Created.hpp"
#include "xos/logger/Interface.hpp"

namespace xos {
namespace mt {
namespace microsoft {
namespace windows {

typedef HANDLE MutexTAttachedT;
typedef mt::Mutex MutexTAttachImplements;
typedef AttachT<MutexTAttachedT, int, 0, AttachException, MutexTAttachImplements> MutexTAttach;
typedef AttachedT<MutexTAttachedT, int, 0, AttachException, MutexTAttach> MutexTAttached;
typedef CreatedT<MutexTAttachedT, int, 0, CreateException, MutexTAttach, MutexTAttached> MutexTCreated;
typedef MutexTAttach MutexTImplements;
typedef MutexTCreated MutexTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MutexT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = MutexTImplements, class TExtends = MutexTExtends>

class _EXPORT_CLASS MutexT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    MutexT(HANDLE attachedTo, bool isCreated)
    : Extends(attachedTo, isCreated) {
    }
    MutexT(HANDLE attachedTo): Extends(attachedTo) {
    }
    MutexT(bool initallyLocked) {
        if (!(this->Create(initallyLocked))) {
            CreateException e(CreateFailed);
            throw (e);
        }
    }
    MutexT() {
        if (!(this->Create())) {
            CreateException e(CreateFailed);
            throw (e);
        }
    }
    virtual ~MutexT() {
        if (!(this->Destroyed())) {
            CreateException e(DestroyFailed);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::Create;
    virtual bool Create(bool initallyLocked) {
        HANDLE detached = 0;

        if ((detached = CreateAttached(initallyLocked))) {
            this->SetIsCreated();
            return detached;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE CreateAttached() {
        bool initallyLocked = false;
        return this->CreateAttached(initallyLocked);
    }
    virtual HANDLE CreateAttached(bool initallyLocked) {
        HANDLE detached = 0;

        if ((this->Destroyed())) {
            if ((detached = CreateDetached(initallyLocked))) {
                this->Attach(detached);
                return detached;
            }
        }
        return 0;
    }
    virtual HANDLE CreateDetached() const {
        bool initallyLocked = false;
        return CreateDetached(initallyLocked);
    }
    virtual HANDLE CreateDetached(bool initallyLocked) const {
        BOOL bInitialOwner = (initallyLocked)?(TRUE):(FALSE);
        LPSECURITY_ATTRIBUTES lpMutexAttributes = NULL;
        LPCTSTR lpName = NULL;
        HANDLE detached = 0;

        XOS_IF_LOG_DEBUG("CreateMutex(lpMutexAttributes, bInitialOwner, lpName)...");
        if ((detached = CreateMutex(lpMutexAttributes, bInitialOwner, lpName))) {
            return detached;
        } else {
            DWORD dwError = GetLastError();
            XOS_IF_LOG_ERROR("...failed dwError = " << dwError << " on CreateMutex(lpMutexAttributes, bInitialOwner, lpName)");
        }
        return 0;
    }
    virtual bool DestroyDetached(HANDLE detached) const {
        if ((detached)) {
            XOS_IF_LOG_DEBUG("CloseHandle(detached)...");
            if ((CloseHandle(detached))) {
                return true;
            } else {
                DWORD dwError  = GetLastError();
                XOS_IF_LOG_ERROR("...failed dwError = " << dwError << " on CloseHandle(detached)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() {
        if (LockSuccess == (UntimedLock())) {
            return true;
        }
        return false;
    }
    virtual bool Unlock() {
        HANDLE detached = 0;

        if ((detached = this->m_attachedTo)) {
            DWORD dwMilliseconds = INFINITE;
            DWORD dwResult = 0;

            XOS_IF_LOG_DEBUG("ReleaseMutex(detached)...");
            if ((ReleaseMutex(detached))) {
                return true;
            } else {
                DWORD dwError  = GetLastError();
                XOS_IF_LOG_ERROR("...failed dwError = " << dwError << " on ReleaseMutex(detached)");
            }
        }
        return false;
    }
    virtual LockStatus TryLock() {
        return TimedLock(0);
    }
    virtual LockStatus TimedLock(mseconds_t milliseconds) {
            if (0 > (milliseconds)) {
                return UntimedLock();
            } else {
                HANDLE detached = 0;

                if ((detached = this->m_attachedTo)) {
                    DWORD dwMilliseconds = (DWORD)(milliseconds);
                    DWORD dwResult = 0;

                    XOS_IF_LOG_TRACE("WaitForSingleObject(detached, dwMilliseconds)...");
                    if (WAIT_OBJECT_0 != (dwResult = WaitForSingleObject(detached, dwMilliseconds))) {
                        switch(dwResult) {
                        case WAIT_TIMEOUT:
                            XOS_IF_LOG_TRACE("...WAIT_TIMEOUT dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                            return LockBusy;
                        case WAIT_ABANDONED:
                            XOS_IF_LOG_ERROR("...WAIT_ABANDONED dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                            return LockInterrupted;
                        default:
                            XOS_IF_LOG_ERROR("...failed dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                            return LockFailed;
                        }
                    } else {
                        XOS_IF_LOG_DEBUG("...WaitForSingleObject(detached, dwMilliseconds)");
                        return LockSuccess;
                    }
                }
            }
        return LockFailed;
    }
    virtual LockStatus UntimedLock() {
        HANDLE detached = 0;

        if ((detached = this->m_attachedTo)) {
            DWORD dwMilliseconds = INFINITE;
            DWORD dwResult = 0;

            XOS_IF_LOG_DEBUG("WaitForSingleObject(detached, dwMilliseconds)...");
            if (WAIT_OBJECT_0 != (dwResult = WaitForSingleObject(detached, dwMilliseconds))) {
                switch(dwResult) {
                case WAIT_TIMEOUT:
                    XOS_IF_LOG_ERROR("...WAIT_TIMEOUT dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                    return LockBusy;
                case WAIT_ABANDONED:
                    XOS_IF_LOG_ERROR("...WAIT_ABANDONED dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                    return LockInterrupted;
                default:
                    XOS_IF_LOG_ERROR("...failed dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                    return LockFailed;
                }
            } else {
                XOS_IF_LOG_DEBUG("...WaitForSingleObject(detached, dwMilliseconds)");
                return LockSuccess;
            }
        }
        return LockFailed;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MutexT<> Mutex;

namespace logger {

typedef LoggedT<false> MutexTLogged;
typedef mt::MutexT<MutexTLogged> MutexTAttachImplements;
typedef AttachT<MutexTAttachedT, int, 0, AttachException, MutexTAttachImplements> MutexTAttach;
typedef AttachedT<MutexTAttachedT, int, 0, AttachException, MutexTAttach> MutexTAttached;
typedef CreatedT<MutexTAttachedT, int, 0, CreateException, MutexTAttach, MutexTAttached> MutexTCreated;
typedef MutexTAttach MutexTImplements;
typedef MutexTCreated MutexTExtends;
typedef MutexT<MutexTImplements, MutexTExtends> Mutex;

} // namespace logger

} // namespace windows
} // namespace microsoft 
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_MICROSOFT_WINDOWS_MUTEX_HPP 
