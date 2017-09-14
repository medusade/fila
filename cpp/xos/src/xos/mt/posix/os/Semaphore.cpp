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
#include "xos/mt/posix/os/Semaphore.hpp"

namespace xos {
namespace mt {
namespace posix {
namespace os {

} // namespace os
} // namespace posix 
} // namespace mt 
} // namespace xos 

#if !defined(WINDOWS)
#if defined(MACOSX)
#if (__MAC_OS_X_VERSION_MAX_ALLOWED <= __MAC_OS_X_VERSION_MAX_ALLOWED_NO_POSIX_SEM)
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
sem_t *sem_open(const char *name, int oflag, ...) {
    return 0;
}
int sem_close(sem_t *sem) {
    return -1;
}
int sem_unlink(const char *name) {
    return -1;
}
int sem_getvalue(sem_t *sem, int *sval) {
    return -1;
}
int semctl(int semid, int semnum, int cmd, ...) {
    return -1;
}
int semget(key_t key, int nsems, int semflg) {
    return -1;
}
int semop(int semid, struct sembuf *sops, size_t nsops) {
    return -1;
}
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int sem_init(sem_t *sem, int pshared, unsigned int value) {
    if ((sem) && (!pshared)) {
        ::xos::mt::posix::os::Semaphore* semaphore = 0;
        try {
            if ((semaphore = new ::xos::mt::posix::os::Semaphore(value))) {
                *sem = semaphore;
                return 0;
            }
        } catch (const ::xos::CreateException& e) {
        }
    }
    return -1;
}
int sem_destroy(sem_t *sem) {
    if ((sem)) {
        ::xos::mt::posix::os::Semaphore* semaphore = 0;
        if ((semaphore = ((::xos::mt::posix::os::Semaphore*)(*sem)))) {
            try {
                delete semaphore;
                *sem = (semaphore = 0);
                return 0;
            } catch (const ::xos::CreateException& e) {
            }
        }
    }
    return -1;
}
int sem_post(sem_t *sem) {
    if ((sem)) {
        ::xos::mt::posix::os::Semaphore* semaphore = 0;
        if ((semaphore = ((::xos::mt::posix::os::Semaphore*)(*sem)))) {
            int err = semaphore->sem_post();
            return err;
        }
    }
    return -1;
}
int sem_wait(sem_t *sem) {
    if ((sem)) {
        ::xos::mt::posix::os::Semaphore* semaphore = 0;
        if ((semaphore = ((::xos::mt::posix::os::Semaphore*)(*sem)))) {
            int err = semaphore->sem_wait();
            return err;
        }
    }
    return -1;
}
int sem_trywait(sem_t *sem) {
    if ((sem)) {
        ::xos::mt::posix::os::Semaphore* semaphore = 0;
        if ((semaphore = ((::xos::mt::posix::os::Semaphore*)(*sem)))) {
            int err = semaphore->sem_trywait();
            return err;
        }
    }
    return -1;
}
#else /*/ (__MAC_OS_X_VERSION_MAX_ALLOWED <= __MAC_OS_X_VERSION_MAX_ALLOWED_NO_POSIX_SEM) /*/
#endif /*/ (__MAC_OS_X_VERSION_MAX_ALLOWED <= __MAC_OS_X_VERSION_MAX_ALLOWED_NO_POSIX_SEM) /*/
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout) {
    if ((sem)) {
        ::xos::mt::posix::os::Semaphore* semaphore = 0;
        if ((semaphore = ((::xos::mt::posix::os::Semaphore*)(*sem)))) {
            int err = semaphore->sem_timedwait(abs_timeout);
            return err;
        }
    }
    return -1;
}
#else // defined(MACOSX)
#endif // defined(MACOSX)
#else // !defined(WINDOWS)
#endif // !defined(WINDOWS)
