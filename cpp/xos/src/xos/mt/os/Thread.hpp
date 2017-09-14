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
#ifndef _XOS_MT_OS_THREAD_HPP
#define _XOS_MT_OS_THREAD_HPP

#include "xos/mt/os/Os.hpp"
#include "xos/mt/Thread.hpp"

#if defined(WINDOWS)
// Windows
#include "xos/mt/microsoft/windows/Thread.hpp"
#elif defined(MACOSX)
// MacOSX
#include "xos/mt/apple/osx/Thread.hpp"
#else // defined(WINDOWS)
// Unix
#include "xos/mt/posix/Thread.hpp"
#endif // defined(WINDOWS)

namespace xos {
namespace mt {
namespace os {

typedef os::Thread Thread;
namespace crt {
typedef os::crt::Thread Thread;
} // namespace crt

} // namespace os
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_OS_THREAD_HPP 
