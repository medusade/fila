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
#ifndef _XOS_MT_OS_SEMAPHORE_HPP
#define _XOS_MT_OS_SEMAPHORE_HPP

#include "xos/mt/semaphore.hpp"
#include "xos/mt/os/os.hpp"

#if defined(WINDOWS)
// windows
#include "xos/mt/microsoft/windows/semaphore.hpp"
#elif defined(MACOSX)
// macosx
#include "xos/mt/apple/osx/semaphore.hpp"
#else // defined(WINDOWS)
// unix
#include "xos/mt/posix/semaphore.hpp"
#endif // defined(WINDOWS)

namespace xos {
namespace mt {
namespace os {

typedef os::semaphore semaphore;

} // namespace os
} // namespace mt 
} // namespace xos 

#endif // _XOS_MT_OS_SEMAPHORE_HPP 
