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
///   File: DLLibraryMain.cpp
///
/// Author: $author$
///   Date: 10/23/2016
///////////////////////////////////////////////////////////////////////
#include "fila/os/os/DLLibrary.hpp"

#if defined(WINDOWS)
// Windows
#include "fila/os/microsoft/windows/DLLibraryMain.cpp"
#elif defined(MACOSX)
// MacOSX
#include "fila/os/apple/osx/DLLibraryMain.cpp"
#else // defined(WINDOWS)
// Unix
#include "fila/os/posix/DLLibraryMain.cpp"
#endif // defined(WINDOWS)

namespace fila {
namespace os {
namespace os {

} // namespace os 
} // namespace os 
} // namespace fila 
