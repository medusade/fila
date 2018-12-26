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
///   File: DLLibraryMain.hpp
///
/// Author: $author$
///   Date: 12/25/2018
///////////////////////////////////////////////////////////////////////
#ifndef _FILA_APP_CONSOLE_LIBHELLO_DLLIBRARYMAIN_HPP
#define _FILA_APP_CONSOLE_LIBHELLO_DLLIBRARYMAIN_HPP

#include "fila/os/os/DLLibraryMain.hpp"

namespace fila {
namespace app {
namespace console {
namespace libhello {

typedef os::os::DLLibraryMain::Implements DLLibraryMainImplements;
typedef os::os::DLLibraryMain DLLibraryMainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: DLLibraryMain
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS DLLibraryMain
: virtual public DLLibraryMainImplements, public DLLibraryMainExtends {
public:
    typedef DLLibraryMainImplements Implements;
    typedef DLLibraryMainExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    DLLibraryMain() {}
    virtual ~DLLibraryMain() {}
private:
    DLLibraryMain(const DLLibraryMain& copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS DLLibraryMain

} // namespace libhello
} // namespace console 
} // namespace app 
} // namespace fila 

#endif // _FILA_APP_CONSOLE_LIBHELLO_DLLIBRARYMAIN_HPP 
