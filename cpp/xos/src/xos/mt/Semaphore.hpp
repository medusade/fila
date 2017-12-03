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
///   Date: 8/28/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_SEMAPHORE_HPP
#define _XOS_MT_SEMAPHORE_HPP

#include "xos/base/Acquired.hpp"
#include "xos/base/Waited.hpp"
#include "xos/base/Created.hpp"
#include "xos/base/Logged.hpp"

namespace xos {
namespace mt {

typedef Logged SemaphoreTLoggedImplements;
typedef Acquired SemaphoreTAcquiredImplements;
typedef Waited SemaphoreTWaitedImplements;
typedef Create SemaphoreTCreateImplements;
///////////////////////////////////////////////////////////////////////
///  Class: SemaphoreT
///////////////////////////////////////////////////////////////////////
template
<class TLoggedImplements = SemaphoreTLoggedImplements,
 class TAcquiredImplements = SemaphoreTAcquiredImplements,
 class TWaitedImplements = SemaphoreTWaitedImplements,
 class TCreateImplements = SemaphoreTCreateImplements>
class _EXPORT_CLASS SemaphoreT
: virtual public TAcquiredImplements,
  virtual public TWaitedImplements,
  virtual public TLoggedImplements,
  virtual public TCreateImplements {
public:
    typedef TAcquiredImplements AcquiredImplements;
    typedef TWaitedImplements WaitedImplements;
    typedef TLoggedImplements LoggedImplements;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Wait() { 
        return this->Acquire(); 
    }
    virtual WaitStatus TryWait() { 
        if ((AcquireSuccess == this->TryAcquire())) {
            return WaitSuccess;
        }
        return WaitFailed; 
    }
    virtual WaitStatus TimedWait(mseconds_t milliseconds) { 
        if ((AcquireSuccess == this->TimedAcquire(milliseconds))) {
            return WaitSuccess;
        }
        return WaitFailed; 
    }
    virtual WaitStatus UntimedWait() { 
        if ((AcquireSuccess == this->UntimedAcquire())) {
            return WaitSuccess;
        }
        return WaitFailed; 
    }
    virtual bool Continue() { 
        return this->Release(); 
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef SemaphoreT<> Semaphore;

} // namespace mt
} // namespace xos 

#endif // _XOS_MT_SEMAPHORE_HPP 
