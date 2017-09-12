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
///   File: semaphore.hpp
///
/// Author: $author$
///   Date: 9/10/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_SEMAPHORE_HPP
#define _XOS_MT_SEMAPHORE_HPP

#include "xos/base/acquired.hpp"
#include "xos/base/created.hpp"
#include "xos/base/logged.hpp"

namespace xos {
namespace mt {

typedef logged semaphoret_logged_implements;
typedef acquired semaphoret_acquired_implements;
typedef create semaphoret_create_implements;
///////////////////////////////////////////////////////////////////////
///  class: semaphoret
///////////////////////////////////////////////////////////////////////
template
<class TLogged_implements = semaphoret_logged_implements,
 class TAcquired_implements = semaphoret_acquired_implements,
 class TCreate_implements = semaphoret_create_implements>
class _EXPORT_CLASS semaphoret
: virtual public TAcquired_implements,
  virtual public TLogged_implements,
  virtual public TCreate_implements {
public:
    typedef TAcquired_implements acquired_implements;
    typedef TLogged_implements logged_implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef semaphoret<> semaphore;

} // namespace mt
} // namespace xos 

#endif // _XOS_MT_SEMAPHORE_HPP 
