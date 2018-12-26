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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 12/25/2018
///////////////////////////////////////////////////////////////////////
#ifndef _FILA_APP_CONSOLE_FILA_MAIN_HPP
#define _FILA_APP_CONSOLE_FILA_MAIN_HPP

#include "fila/console/Main.hpp"
#include "fila/lib/fila/Version.hpp"

namespace fila {
namespace app {
namespace console {
namespace fila {

typedef ::fila::console::Main::Implements MainImplements;
typedef ::fila::console::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: Main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: virtual public MainImplements, public MainExtends {
public:
    typedef MainImplements Implements;
    typedef MainExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Main() {
    }
    virtual ~Main() {
    }
private:
    Main(const Main& copy) {
    }
protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t**argv, char_t** env) {
        const ::fila::lib::Version& version = ::fila::lib::fila::Version::Which();
        int err = 0;
        this->OutL(version.Name(), " version = ", version.ToString().Chars(), NULL);
        this->OutLn();
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
}; /// class _EXPORT_CLASS Main

} /// namespace fila
} /// namespace console
} /// namespace app
} /// namespace fila

#endif ///ndef _FILA_APP_CONSOLE_FILA_MAIN_HPP
