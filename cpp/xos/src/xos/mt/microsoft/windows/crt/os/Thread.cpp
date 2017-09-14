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
///   File: Thread.cpp
///
/// Author: $author$
///   Date: 9/12/2017
///////////////////////////////////////////////////////////////////////
#include "xos/mt/microsoft/windows/crt/os/Thread.hpp"

namespace xos {
namespace mt {
namespace microsoft {
namespace windows {
namespace crt {
namespace os {

} // namespace os 
} // namespace crt 
} // namespace windows 
} // namespace microsoft 
} // namespace mt 
} // namespace xos 

#if !defined(WINDOWS)
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
uintptr_t _beginthreadex(
   void *security,
   unsigned stack_size,
   unsigned ( __stdcall *start_address )( void * ),
   void *arglist,
   unsigned initflag,
   unsigned *thrdaddr
) {
    bool initiallySuspended = false;
    try {
        ::xos::mt::microsoft::windows::crt::os::Thread* handle = 0;
        if ((handle = new ::xos::mt::microsoft::windows::crt::os::Thread
             (initiallySuspended, start_address, arglist))) {
            return (uintptr_t)handle;
        }
    } catch (const ::xos::CreateException e) {
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#else // !defined(WINDOWS)
#endif // !defined(WINDOWS)

