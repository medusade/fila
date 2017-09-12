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
#ifndef _XOS_MT_OS_MUTEX_HPP
#define _XOS_MT_OS_MUTEX_HPP

#include "xos/mt/mutex.hpp"
#include "xos/mt/os/os.hpp"

#if defined(WINDOWS)
// windows
#include "xos/mt/microsoft/windows/mutex.hpp"
#elif defined(MACOSX)
// mac_oSX
#include "xos/mt/apple/osx/mutex.hpp"
#else // defined(WINDOWS)
// unix
#include "xos/mt/posix/mutex.hpp"
#endif // defined(WINDOWS)

namespace xos {
namespace mt {
namespace os {

typedef os::mutex mutex;
namespace logger {
typedef os::logger::mutex mutex;
} // namespace logger

} // namespace os
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_OS_MUTEX_HPP 
