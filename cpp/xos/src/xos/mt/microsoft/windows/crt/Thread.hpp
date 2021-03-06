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
#ifndef _XOS_MT_MICROSOFT_WINDOWS_CRT_THREAD_HPP
#define _XOS_MT_MICROSOFT_WINDOWS_CRT_THREAD_HPP

#include "xos/mt/Thread.hpp"
#include "xos/logger/Interface.hpp"

namespace xos {
namespace mt {
namespace microsoft {
namespace windows {
namespace crt {

typedef HANDLE ThreadTAttachedT;
typedef mt::Thread ThreadTAttachImplements;
typedef AttachT<ThreadTAttachedT, int, 0, AttachException, ThreadTAttachImplements> ThreadTAttach;
typedef AttachedT<ThreadTAttachedT, int, 0, AttachException, ThreadTAttach> ThreadTAttached;
typedef CreatedT<ThreadTAttachedT, int, 0, CreateException, ThreadTAttach, ThreadTAttached> ThreadTCreated;
typedef ThreadTAttach ThreadTImplements;
typedef ThreadTCreated ThreadTExtends;
///////////////////////////////////////////////////////////////////////
///  Class: ThreadT
///////////////////////////////////////////////////////////////////////
template
<class TImplements = ThreadTImplements, class TExtends = ThreadTExtends>

class _EXPORT_CLASS ThreadT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    ThreadT(bool initiallySuspended, Ran& ran): m_ran(ran), m_forked(false) {
        if (!(this->Create(initiallySuspended))) {
            CreateException e(CreateFailed);
            throw (e);
        }
    }
    ThreadT(Ran& ran): m_ran(ran), m_forked(false), m_threadId(0) {
        if (!(this->Create())) {
            CreateException e(CreateFailed);
            throw (e);
        }
    }
    ThreadT(bool initiallySuspended): m_ran(*this), m_forked(false) {
        if (!(this->Create(initiallySuspended))) {
            CreateException e(CreateFailed);
            throw (e);
        }
    }
    ThreadT(): m_ran(*this), m_forked(false), m_threadId(0) {
        if (!(this->Create())) {
            CreateException e(CreateFailed);
            throw (e);
        }
    }
    virtual ~ThreadT() {
        if (!(this->Destroyed())) {
            CreateException e(DestroyFailed);
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(bool initiallySuspended) {
        HANDLE detached = 0;
        if ((detached = CreateAttached(initiallySuspended))) {
            this->SetIsCreated();
            return m_forked = true;
        }
        return false;
    }
    virtual bool Create() {
        return Create(false);
    }
    virtual bool Destroy() {
        if ((Joined())) {
            HANDLE detached = 0;
            if ((detached = this->Detach())) {
                return DestroyDetached(detached);
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE CreateAttached(bool initiallySuspended) {
        HANDLE detached = 0;
        if ((this->Destroyed())) {
            unsigned threadId = 0;
            if ((detached = CreateDetached(threadId, initiallySuspended))) {
                this->Attach(detached);
                m_threadId = threadId;
                return detached;
            }
        }
        return 0;
    }
    virtual HANDLE CreateDetached
    (unsigned& threadId, bool initiallySuspended) const {
        unsigned (__stdcall*startAddress)(void*) = ThreadProc;
        void* parameter = ((void*)this);
        unsigned initFlags = (initiallySuspended)?(CREATE_SUSPENDED):(0);
        unsigned stackSize = 0;
        HANDLE detached = 0;
        SECURITY_ATTRIBUTES securityAttributes;

        memset(&securityAttributes, 0, sizeof(securityAttributes));
        securityAttributes.nLength = sizeof(securityAttributes);

        XOS_LOG_DEBUG("_beginthreadex(&securityAttributes, stackSize, startAddress, parameter, initFlags, &threadId)...");
        if (((HANDLE)-1) != (detached = ((HANDLE)_beginthreadex
            (&securityAttributes, stackSize, startAddress,
             parameter, initFlags, &threadId)))) {
            return detached;
        } else {
            int err = errno;
            switch(err) {
            case EACCES:
                XOS_LOG_ERROR("...EACCES err = " << err << " on _beginthreadex(&securityAttributes, stackSize, startAddress, parameter, initFlags, &threadId)");
                break;
            case EAGAIN:
                XOS_LOG_ERROR("...EAGAIN err = " << err << " on _beginthreadex(&securityAttributes, stackSize, startAddress, parameter, initFlags, &threadId)");
                break;
            case EINVAL:
                XOS_LOG_ERROR("...EINVAL err = " << err << " on _beginthreadex(&securityAttributes, stackSize, startAddress, parameter, initFlags, &threadId)");
                break;
            default:
                XOS_LOG_ERROR("...failed err = " << err << " on _beginthreadex(&securityAttributes, stackSize, startAddress, parameter, initFlags, &threadId)");
            }
        }
        return 0;
    }
    virtual bool DestroyDetached(HANDLE detached) const {
        if ((detached)) {
            XOS_LOG_DEBUG("CloseHandle(detached)...");
            if ((CloseHandle(detached))) {
                return true;
            } else {
                DWORD dwError = GetLastError();
                XOS_LOG_ERROR("...failed dwError = " << dwError << " on CloseHandle(detached)");
            }
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Joined() {
        if ((m_forked)) {
            return Join();
        }
        return true;
    }
    virtual bool Join() {
        HANDLE detached = 0;
        m_forked = false;
        if ((detached = this->AttachedTo())) {
            if ((JoinDetached(detached))) {
                return true;
            }
        }
        return false;
    }
    virtual JoinStatus TryJoin() {
        return TimedJoin(0);
    }
    virtual JoinStatus TimedJoin(mseconds_t milliseconds) {
        if (0 > (milliseconds)) {
            return UntimedJoin();
        } else {
            HANDLE detached = 0;
            if ((detached = this->AttachedTo())) {
                DWORD dwMilliseconds = ((DWORD)milliseconds);
                DWORD dwResult = 0;

                XOS_LOG_TRACE("WaitForSingleObject(detached, dwMilliseconds)...");
                if (WAIT_OBJECT_0 != (dwResult = WaitForSingleObject(detached, dwMilliseconds))) {
                    switch(dwResult) {
                    case WAIT_TIMEOUT:
                        XOS_LOG_TRACE("...WAIT_TIMEOUT dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                        return JoinBusy;
                    case WAIT_ABANDONED:
                        XOS_LOG_ERROR("...WAIT_ABANDONED dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                        return JoinInterrupted;
                    default:
                        XOS_LOG_ERROR("...failed dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                        return JoinFailed;
                    }
                } else {
                    XOS_LOG_DEBUG("...WaitForSingleObject(detached, dwMilliseconds)");
                    return JoinSuccess;
                }
            }
        }
        return JoinFailed;
    }
    virtual JoinStatus UntimedJoin() {
        HANDLE detached = 0;
        m_forked = false;
        if ((detached = this->AttachedTo())) {
            return UntimedJoinDetached(detached);
        }
        return JoinFailed;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool JoinDetached(HANDLE detached) const {
        if (JoinSuccess == (UntimedJoinDetached(detached))) {
            return true;
        }
        return false;
    }
    virtual JoinStatus UntimedJoinDetached(HANDLE detached) const {
        if ((detached)) {
            DWORD dwMilliseconds = ((DWORD)INFINITE);
            DWORD dwResult = 0;

            XOS_LOG_DEBUG("WaitForSingleObject(detached, dwMilliseconds)...");
            if (WAIT_OBJECT_0 != (dwResult = WaitForSingleObject(detached, dwMilliseconds))) {
                switch(dwResult) {
                case WAIT_TIMEOUT:
                    XOS_LOG_ERROR("...WAIT_TIMEOUT dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                    return JoinBusy;
                case WAIT_ABANDONED:
                    XOS_LOG_ERROR("...WAIT_ABANDONED dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                    return JoinInterrupted;
                default:
                    XOS_LOG_ERROR("...failed dwResult = " << dwResult << " on WaitForSingleObject(detached, dwMilliseconds)...");
                    return JoinFailed;
                }
            } else {
                XOS_LOG_DEBUG("...WaitForSingleObject(detached, dwMilliseconds)");
                return JoinSuccess;
            }
        }
        return JoinFailed;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual HANDLE Detach() {
        m_forked = false;
        m_threadId = 0;
        return Extends::Detach();
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void Run() {
        XOS_LOG_DEBUG("...");
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    static unsigned __stdcall ThreadProc(void* param) {
        unsigned result = 0;
        ThreadT* t = 0;

        XOS_LOG_DEBUG("in...");
        if ((t = ((ThreadT*)param))) {
            XOS_LOG_DEBUG("t->m_ran.Run()...");
            t->m_ran.Run();
            XOS_LOG_DEBUG("...t->m_ran.Run()");
        } else {
            XOS_LOG_ERROR("...unexpected 0 = ((ThreadT*)param)");
        }
        XOS_LOG_DEBUG("...out");
        return result;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    Ran& m_ran;
    bool m_forked;
    unsigned m_threadId;
};
typedef ThreadT<> Thread;

} // namespace crt
} // namespace windows 
} // namespace microsoft 
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_MICROSOFT_WINDOWS_CRT_THREAD_HPP 
