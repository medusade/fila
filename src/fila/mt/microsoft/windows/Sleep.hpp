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
///   File: Sleep.hpp
///
/// Author: $author$
///   Date: 10/2/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FILA_MT_MICROSOFT_WINDOWS_SLEEP_HPP
#define _FILA_MT_MICROSOFT_WINDOWS_SLEEP_HPP

#include "fila/mt/Sleep.hpp"
#include "crono/io/Logger.hpp"

namespace fila {
namespace mt {
namespace microsoft {
namespace windows {
	
inline void SleepMilliseconds(mseconds_t milliseconds) {
	if (1000 <= (milliseconds)) {
		CRONO_LOG_DEBUG("::Sleep(milliseconds = " << milliseconds << ")...");
	} else {
		if (500 <= (milliseconds)) {
			CRONO_LOG_TRACE("::Sleep(milliseconds = " << milliseconds << ")...");
		}
	}
    ::Sleep(milliseconds);
}
inline void SleepSeconds(seconds_t seconds) {
    SleepMilliseconds(seconds*1000);
}

} // namespace windows 
} // namespace microsoft 
} // namespace mt 
} // namespace fila 

#endif // _FILA_MT_MICROSOFT_WINDOWS_SLEEP_HPP 
