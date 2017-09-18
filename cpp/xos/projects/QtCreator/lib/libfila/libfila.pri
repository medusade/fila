########################################################################
# Copyright (c) 1988-2017 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: libfila.pri
#
# Author: $author$
#   Date: 8/5/2017
########################################################################

libfila_INCLUDEPATH += \
$${fila_INCLUDEPATH} \

libfila_DEFINES += \

########################################################################
# base
libfila_HEADERS += \
$${FILA_SRC}/xos/mt/os/Threads.hpp \
$${FILA_SRC}/xos/mt/os/Thread.hpp \
$${FILA_SRC}/xos/mt/microsoft/windows/crt/Thread.hpp \
$${FILA_SRC}/xos/mt/microsoft/windows/crt/os/Thread.hpp \
$${FILA_SRC}/xos/mt/microsoft/windows/Thread.hpp \
$${FILA_SRC}/xos/mt/microsoft/windows/os/Thread.hpp \
$${FILA_SRC}/xos/mt/apple/osx/Thread.hpp \
$${FILA_SRC}/xos/mt/posix/Thread.hpp \
$${FILA_SRC}/xos/mt/posix/os/Thread.hpp \
$${FILA_SRC}/xos/mt/Thread.hpp \
\
$${FILA_SRC}/xos/mt/os/Semaphores.hpp \
$${FILA_SRC}/xos/mt/os/Semaphore.hpp \
$${FILA_SRC}/xos/mt/microsoft/windows/Semaphore.hpp \
$${FILA_SRC}/xos/mt/microsoft/windows/os/Semaphore.hpp \
$${FILA_SRC}/xos/mt/apple/osx/Semaphore.hpp \
$${FILA_SRC}/xos/mt/apple/mach/Semaphore.hpp \
$${FILA_SRC}/xos/mt/posix/Semaphore.hpp \
$${FILA_SRC}/xos/mt/posix/os/Semaphore.hpp \
$${FILA_SRC}/xos/mt/Semaphore.hpp \
\
$${FILA_SRC}/xos/mt/os/Mutexes.hpp \
$${FILA_SRC}/xos/mt/os/Mutex.hpp \
$${FILA_SRC}/xos/mt/microsoft/windows/Mutex.hpp \
$${FILA_SRC}/xos/mt/microsoft/windows/os/Mutex.hpp \
$${FILA_SRC}/xos/mt/apple/osx/Mutex.hpp \
$${FILA_SRC}/xos/mt/posix/Mutex.hpp \
$${FILA_SRC}/xos/mt/Mutex.hpp \

libfila_SOURCES += \
$${FILA_SRC}/xos/mt/os/Threads.cpp \
$${FILA_SRC}/xos/mt/os/Semaphores.cpp \
$${FILA_SRC}/xos/mt/os/Mutexes.cpp \

