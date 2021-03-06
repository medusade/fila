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
///   File: mutex.hpp
///
/// Author: $author$
///   Date: 9/9/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_MUTEX_HPP
#define _XOS_MT_MUTEX_HPP

#include "xos/base/locked.hpp"
#include "xos/base/created.hpp"
#include "xos/base/logged.hpp"

namespace xos {
namespace mt {

typedef logged mutext_logged_implements;
typedef locked mutext_locked_implements;
typedef create mutext_create_implements;
///////////////////////////////////////////////////////////////////////
///  class: mutext
///////////////////////////////////////////////////////////////////////
template
<class TLogged_implements = mutext_logged_implements,
 class TLocked_implements = mutext_locked_implements,
 class TCreate_implements = mutext_create_implements>
class _EXPORT_CLASS mutext
: virtual public TLocked_implements,
  virtual public TLogged_implements,
  virtual public TCreate_implements {
public:
    typedef TLocked_implements locked_implements;
    typedef TLogged_implements logged_implements;
    typedef TCreate_implements create_implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef mutext<> mutex;

} // namespace mt
} // namespace xos 

#endif // _XOS_MT_MUTEX_HPP 
