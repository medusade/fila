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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 8/18/2017
///////////////////////////////////////////////////////////////////////
#ifndef _FILA_CONSOLE_MT_GETOPT_MAIN_HPP
#define _FILA_CONSOLE_MT_GETOPT_MAIN_HPP

#include "fila/console/mt/getopt/MainOpt.hpp"
#include "fila/console/mt/Main.hpp"
#include "nadir/console/getopt/Main.hpp"

namespace fila {
namespace console {
namespace mt {
namespace getopt {

typedef nadir::console::getopt::MainImplements MainImplements;
typedef mt::MainT
<MainOpt, MainImplements, nadir::console::getopt::Main> MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TOptImplements = MainOpt,
 class TImplements = MainImplements, class TExtends = MainExtends>

class _EXPORT_CLASS MainT: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef typename Implements::char_t char_t;
    typedef typename Implements::endchar_t endchar_t;
    static const endchar_t endchar = Implements::endchar;
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: MainT
    ///////////////////////////////////////////////////////////////////////
    MainT() {
    }
    virtual ~MainT() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainT<> Main;

} // namespace getopt 
} // namespace mt 
} // namespace console 
} // namespace fila 

#endif // _FILA_CONSOLE_MT_GETOPT_MAIN_HPP 
