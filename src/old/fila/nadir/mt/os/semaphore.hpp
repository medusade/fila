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
///   Date: 5/8/2017
///////////////////////////////////////////////////////////////////////
#ifndef _FILA_NADIR_MT_OS_SEMAPHORE_HPP
#define _FILA_NADIR_MT_OS_SEMAPHORE_HPP

#include "fila/nadir/mt/semaphore.hpp"
#include "fila/nadir/mt/os/os.hpp"

#if defined(WINDOWS)
// Windows
#include "fila/nadir/mt/microsoft/windows/semaphore.hpp"
#elif defined(MACOSX)
// MacOSX
#include "fila/nadir/mt/apple/osx/semaphore.hpp"
#else // defined(WINDOWS)
// Unix
#include "fila/nadir/mt/posix/semaphore.hpp"
#endif // defined(WINDOWS)

namespace fila {
namespace mt {
namespace os {

typedef os::semaphore semaphore;

} // namespace os
} // namespace mt 
} // namespace fila 

#endif // _FILA_NADIR_MT_OS_SEMAPHORE_HPP 
        

