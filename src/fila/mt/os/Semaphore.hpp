///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
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
///   Date: 12/25/2018
///////////////////////////////////////////////////////////////////////
#ifndef _FILA_MT_OS_SEMAPHORE_HPP
#define _FILA_MT_OS_SEMAPHORE_HPP

#include "fila/mt/os/Os.hpp"

#if defined(WINDOWS)
// Windows
#include "fila/mt/microsoft/windows/Semaphore.hpp"
#elif defined(MACOSX)
// MacOSX
#include "fila/mt/apple/osx/Semaphore.hpp"
#else // defined(WINDOWS)
// Unix
#include "fila/mt/posix/Semaphore.hpp"
#endif // defined(WINDOWS)

namespace fila {
namespace mt {
namespace os {

typedef os::Semaphore Semaphore;

} // namespace os
} // namespace mt 
} // namespace fila 

#endif // _FILA_MT_OS_SEMAPHORE_HPP 
