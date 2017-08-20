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
#ifndef _FILA_CONSOLE_MT_MAIN_HPP
#define _FILA_CONSOLE_MT_MAIN_HPP

#include "nadir/console/Main.hpp"
#include "xos/console/mt/Locked.hpp"

namespace fila {
namespace console {
namespace mt {

typedef nadir::console::MainArg MainArg;
typedef nadir::console::MainImplements MainImplements;
typedef nadir::console::Main MainExtends;
///////////////////////////////////////////////////////////////////////
///  Class: MainT
///////////////////////////////////////////////////////////////////////
template
<class TArgImplements = MainArg,
 class TImplements = MainImplements, class TExtends = MainExtends>
class _EXPORT_CLASS MainT
: virtual public xos::Locked, virtual public TArgImplements,
  virtual public TImplements, public TExtends {
public:
    typedef TArgImplements ArgImplements;
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    /// Class: Locked
    ///////////////////////////////////////////////////////////////////////
    class _EXPORT_CLASS Locked: public ::xos::console::mt::Locked {
    public:
        Locked(xos::Locked& locked): ::xos::console::mt::Locked(locked) {}
    friend class MainT;
    };
    ///////////////////////////////////////////////////////////////////////
    /// Constructor: MainT
    ///////////////////////////////////////////////////////////////////////
    MainT() {
    }
    virtual ~MainT() {
    }
    ///////////////////////////////////////////////////////////////////////
    /// Function: Lock/Unlock
    ///////////////////////////////////////////////////////////////////////
    virtual bool Lock() {
        xos::Locked* locked = Locked::TheLocked();
        if ((locked)) {
            return locked->Lock();
        }
        return false;
    }
    virtual bool Unlock() {
        xos::Locked* locked = Locked::TheLocked();
        if ((locked)) {
            return locked->Unlock();
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef MainT<> Main;

} // namespace mt 
} // namespace console 
} // namespace fila 

#endif // _FILA_CONSOLE_MT_MAIN_HPP 

        

