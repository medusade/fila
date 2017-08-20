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
///   Date: 8/6/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_MUTEX_HPP
#define _XOS_MT_MUTEX_HPP

#include "xos/base/Locked.hpp"
#include "xos/base/Created.hpp"
#include "xos/base/Logged.hpp"

namespace xos {
namespace mt {

typedef Logged MutexTLoggedImplements;
typedef Locked MutexTLockedImplements;
typedef Create MutexTCreateImplements;
///////////////////////////////////////////////////////////////////////
///  Class: MutexT
///////////////////////////////////////////////////////////////////////
template
<class TLoggedImplements = MutexTLoggedImplements,
 class TLockedImplements = MutexTLockedImplements,
 class TCreateImplements = MutexTCreateImplements>
class _EXPORT_CLASS MutexT
: virtual public TLockedImplements,
  virtual public TLoggedImplements,
  virtual public TCreateImplements {
public:
    typedef TLockedImplements LockedImplements;
    typedef TLoggedImplements LoggedImplements;
    typedef TCreateImplements CreateImplements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MutexT<> Mutex;

} // namespace mt
} // namespace xos 

#endif // _XOS_MT_MUTEX_HPP 
