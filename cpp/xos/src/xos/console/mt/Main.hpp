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
///   Date: 8/7/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_MT_MAIN_HPP
#define _XOS_CONSOLE_MT_MAIN_HPP

#include "fila/console/mt/Main.hpp"
#include "xos/console/mt/Locked.hpp"
#include "xos/console/Main.hpp"

namespace xos {
namespace console {
namespace mt {

typedef fila::console::mt::MainImplements MainImplements;
typedef fila::console::mt::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TArgImplements = MainArg,
 class TImplements = MainImplements, class TExtends = MainExtends>

class _EXPORT_CLASS MainT
: virtual public TArgImplements, virtual public TImplements, public TExtends {
public:
    typedef TArgImplements ArgImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;
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

} // namespace mt 
} // namespace console 
} // namespace xos 

#endif // _XOS_CONSOLE_MT_MAIN_HPP 
