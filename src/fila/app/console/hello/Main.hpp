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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 9/24/2016
///////////////////////////////////////////////////////////////////////
#ifndef _FILA_APP_CONSOLE_HELLO_MAIN_HPP
#define _FILA_APP_CONSOLE_HELLO_MAIN_HPP

#include "fila/console/Main.hpp"
#include "fila/mt/os/Thread.hpp"
#include "fila/mt/os/Semaphore.hpp"
#include "fila/mt/os/Mutex.hpp"
#include "fila/mt/os/Sleep.hpp"
#include "fila/os/os/DLLibrary.hpp"
#include "fila/os/microsoft/windows/DLLibrary.hpp"
#include "crono/io/Logger.hpp"

namespace fila {
namespace app {
namespace console {
namespace hello {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Main: public fila::console::Main {
public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int Run(int argc, char_t **argv, char_t **env) {
        class Thread: public mt::os::Thread {
        public:
            Thread(mt::os::Semaphore& sem): m_sem(sem) {}
            virtual void Run() {
                CRONO_LOG_DEBUG("mt::os::SleepSeconds(1)...");
                mt::os::SleepSeconds(1);
                CRONO_LOG_DEBUG("m_sem.Release()...");
                m_sem.Release();
            }
            mt::os::Semaphore& m_sem;
        };
        const char* libraryName = "libfila-hello";
        if ((argc > (optind)) && (argv[optind]) && (argv[optind][0])) {
            libraryName = argv[optind];
        }
        try {
            os::os::DLLibrary dl;
            dl.Open(libraryName);
        } catch (const OpenException& e) {
            CRONO_LOG_ERROR("...caught const OpenException& e = \"" << e.StatusToChars() << "\"");
        }
        return 0;
        try {
            mt::os::Semaphore sem;
            mt::os::Mutex mutex;
            Thread thread(sem);
            Locker lock(mutex);
            Acquirer acquire(sem);

            CRONO_LOG_DEBUG("OutLn(\"Hello\")...");
            OutLn("Hello");
        } catch (const AcquireException& e) {
            CRONO_LOG_ERROR("...caught const AcquireException& e = \"" << e.StatusToChars() << "\"");
        } catch (const LockException& e) {
            CRONO_LOG_ERROR("...caught const LockException& e = \"" << e.StatusToChars() << "\"");
        } catch (const CreateException& e) {
            CRONO_LOG_ERROR("...caught const CreateException& e = \"" << e.StatusToChars() << "\"");
        }
        return 0;
    }
};

} // namespace hello
} // namespace console 
} // namespace app 
} // namespace fila 

#endif // _FILA_APP_CONSOLE_HELLO_MAIN_HPP 
