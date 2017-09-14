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
///   File: Semaphore.cpp
///
/// Author: $author$
///   Date: 9/12/2017
///////////////////////////////////////////////////////////////////////
#include "xos/mt/microsoft/windows/os/Semaphore.hpp"

namespace xos {
namespace mt {
namespace microsoft {
namespace windows {
namespace os {

} // namespace os 
} // namespace windows 
} // namespace microsoft 
} // namespace mt 
} // namespace xos 

#if !defined(WINDOWS)
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
HANDLE WINAPI CreateSemaphore(
  _In_opt_ LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
  _In_     LONG                  lInitialCount,
  _In_     LONG                  lMaximumCount,
  _In_opt_ LPCTSTR               lpName
) {
    try {
        ::xos::mt::microsoft::windows::os::Semaphore* handle = 0;
        if ((handle = new ::xos::mt::microsoft::windows::os::Semaphore)) {
            return handle;
        }
    } catch (const ::xos::CreateException e) {
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#endif // !defined(WINDOWS)
