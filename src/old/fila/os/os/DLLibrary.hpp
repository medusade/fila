///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
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
///   File: DLLibrary.hpp
///
/// Author: $author$
///   Date: 10/23/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FILA_OS_OS_DLLIBRARY_HPP
#define _FILA_OS_OS_DLLIBRARY_HPP

#include "fila/os/os/Os.hpp"

#if defined(WINDOWS)
// Windows
#include "fila/os/microsoft/windows/DLLibrary.hpp"
#elif defined(MACOSX)
// MacOSX
#include "fila/os/apple/osx/DLLibrary.hpp"
#else // defined(WINDOWS)
// Unix
#include "fila/os/posix/DLLibrary.hpp"
#endif // defined(WINDOWS)

namespace fila {
namespace os {
namespace os {

typedef os::DLLibrary DLLibrary;

} // namespace os 
} // namespace os 
} // namespace fila 

#endif // _FILA_OS_OS_DLLIBRARY_HPP 
