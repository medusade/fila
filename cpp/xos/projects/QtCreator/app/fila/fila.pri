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
#   File: fila.pri
#
# Author: $author$
#   Date: 9/4/2017
#
# QtCreator .pri file for fila executable fila
########################################################################

fila_exe_TARGET = fila

########################################################################
fila_exe_INCLUDEPATH += \
$${fila_INCLUDEPATH} \

fila_exe_DEFINES += \
$${fila_DEFINES} \
XOS_APP_CONSOLE_FILA_THE_MAIN \

########################################################################
# rostra
fila_exe_HEADERS += \
$${ROSTRA_SRC}/xos/platform/platform.hpp \
$${ROSTRA_SRC}/xos/platform/platform_windows.hpp \
$${ROSTRA_SRC}/xos/platform/platform_unix.hpp \
$${ROSTRA_SRC}/xos/platform/platform_unix.h \

fila_exe_SOURCES += \
$${ROSTRA_SRC}/xos/platform/platform.cpp \

########################################################################
# nadir
fila_exe_HEADERS += \
$${NADIR_SRC}/xos/console/Locked.hpp \

fila_exe_SOURCES += \
$${NADIR_SRC}/xos/console/Locked.cpp \

########################################################################
# patrona
fila_exe_HEADERS += \
$${PATRONA_SRC}/xos/base/Ran.hpp \
$${PATRONA_SRC}/xos/base/Joined.hpp \
$${PATRONA_SRC}/xos/base/Suspended.hpp \
$${PATRONA_SRC}/xos/base/Locked.hpp \

fila_exe_SOURCES += \
$${PATRONA_SRC}/xos/base/Ran.cpp \
$${PATRONA_SRC}/xos/base/Joined.cpp \
$${PATRONA_SRC}/xos/base/Suspended.cpp \

########################################################################
# fila
fila_exe_HEADERS += \
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

fila_exe_SOURCES += \
$${FILA_SRC}/xos/mt/os/Threads.cpp \
$${FILA_SRC}/xos/mt/os/Semaphores.cpp \
$${FILA_SRC}/xos/mt/os/Mutexes.cpp \

########################################################################
# fila
fila_exe_HEADERS += \
$${FILA_SRC}/xos/app/console/fila/Main.hpp \
$${FILA_SRC}/xos/app/console/fila/MainOpt.hpp \
$${FILA_SRC}/xos/console/mt/Main_main.hpp \

fila_exe_SOURCES += \
$${FILA_SRC}/xos/app/console/fila/Main.cpp \
$${FILA_SRC}/xos/app/console/fila/MainOpt.cpp \
$${FILA_SRC}/xos/console/mt/Main_main.cpp \

########################################################################
fila_exe_LIBS += \
$${fila_LIBS} \

