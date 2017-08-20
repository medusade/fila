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
///   File: Locked.hpp
///
/// Author: $author$
///   Date: 8/11/2017
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CONSOLE_MT_LOCKED_HPP
#define _XOS_CONSOLE_MT_LOCKED_HPP

#include "xos/base/Locked.hpp"

namespace xos {
namespace console {
namespace mt {

///////////////////////////////////////////////////////////////////////
/// Class: Locked
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Locked: public xos::Locked {
public:
    Locked(xos::Locked& locked): m_locked(locked) {
        xos::Locked*& theLocked = TheLocked();
        if (!(theLocked)) {
            theLocked = this;
        } else {
        }
    }
    virtual ~Locked() {
        xos::Locked*& theLocked = TheLocked();
        if ((this == theLocked)) {
            theLocked = 0;
        } else {
        }
    }
    virtual bool Lock() {
        return m_locked.Lock();
    }
    virtual bool Unlock() {
        return m_locked.Unlock();
    }
protected:
    static xos::Locked*& TheLocked() {
        static xos::Locked* theLocked = 0;
        return theLocked;
    }
    xos::Locked& m_locked;
};

} // namespace mt
} // namespace console 
} // namespace xos 

#endif // _XOS_CONSOLE_MT_LOCKED_HPP 
