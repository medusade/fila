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
#ifndef _XOS_MT_THREAD_HPP
#define _XOS_MT_THREAD_HPP

#include "xos/base/Ran.hpp"
#include "xos/base/Suspended.hpp"
#include "xos/base/Joined.hpp"
#include "xos/base/Created.hpp"

namespace xos {
namespace mt {

///////////////////////////////////////////////////////////////////////
///  Class: ThreadTImplementsT
///////////////////////////////////////////////////////////////////////
template
<class TRanImplements = Ran,
 class TSuspendedImplements = Suspended,
 class TJoinedImplements = Joined,
 class TCreateImplements = Create>

class _EXPORT_CLASS ThreadTImplementsT
: virtual public TRanImplements,
  virtual public TSuspendedImplements,
  virtual public TJoinedImplements,
  virtual public TCreateImplements {
public:
    typedef TRanImplements RanImplements;
    typedef TSuspendedImplements SuspendedImplements;
    typedef TJoinedImplements JoinedImplements;
    typedef TCreateImplements CreateImplements;
};
typedef ThreadTImplementsT<> ThreadTImplements;
///////////////////////////////////////////////////////////////////////
///  Class: ThreadT
///////////////////////////////////////////////////////////////////////
template <class TImplements = ThreadTImplements>
class _EXPORT_CLASS ThreadT: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(bool initiallySuspended) { return false; }
    virtual bool Create() { return false; }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef ThreadT<> Thread;

} // namespace mt
} // namespace xos 

#endif // _XOS_MT_THREAD_HPP 

        

