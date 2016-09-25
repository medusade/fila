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
///   File: Acquired.hpp
///
/// Author: $author$
///   Date: 9/24/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FILA_BASE_ACQUIRED_HPP
#define _FILA_BASE_ACQUIRED_HPP

#include "patrona/cpp/xos/base/Acquired.hpp"

namespace fila {

typedef ::patrona::AcquireStatus AcquireStatus;
static const AcquireStatus AcquireSuccess = ::patrona::AcquireSuccess;
static const AcquireStatus AcquireFailed = ::patrona::AcquireFailed;
static const AcquireStatus AcquireBusy = ::patrona::AcquireBusy;
static const AcquireStatus AcquireInterrupted = ::patrona::AcquireInterrupted;
static const AcquireStatus AcquireInvalid = ::patrona::AcquireInvalid;
static const AcquireStatus ReleaseSuccess = ::patrona::ReleaseSuccess;
static const AcquireStatus ReleaseFailed = ::patrona::ReleaseFailed;
static const AcquireStatus ReleaseBusy = ::patrona::ReleaseBusy;
static const AcquireStatus ReleaseInterrupted = ::patrona::ReleaseInterrupted;
static const AcquireStatus ReleaseInvalid = ::patrona::ReleaseInvalid;

typedef ::patrona::AcquireException AcquireException;

typedef ::patrona::Acquired Acquired;
typedef ::patrona::Acquirer Acquirer;
typedef ::patrona::Releaser Releaser;

} // namespace fila

#endif // _FILA_BASE_ACQUIRED_HPP
