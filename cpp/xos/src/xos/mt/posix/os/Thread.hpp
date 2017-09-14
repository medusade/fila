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
///   Date: 9/13/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_MT_POSIX_OS_THREAD_HPP
#define _XOS_MT_POSIX_OS_THREAD_HPP

#include "xos/mt/Thread.hpp"

namespace xos {
namespace mt {
namespace posix {
namespace os {

} // namespace os 
} // namespace posix 
} // namespace mt 
} // namespace xos 

#if !defined(HAS_POSIX_TIMEOUTS)
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int pthread_tryjoin_np(pthread_t thread, void **retval) {
    return -1;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int pthread_timedjoin_np
(pthread_t thread, void **retval, const struct timespec *abstime) {
    return -1;
}
#endif // !defined(HAS_POSIX_TIMEOUTS)

#endif // _XOS_MT_POSIX_OS_THREAD_HPP 
