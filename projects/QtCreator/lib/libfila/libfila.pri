########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   Date: 3/24/2018
#
# QtCreator .pri file for fila library libfila
########################################################################

########################################################################
# libfila

# libfila TARGET
#
libfila_TARGET = fila
libfila_TEMPLATE = lib
libfila_CONFIG += staticlib

# libfila INCLUDEPATH
#
libfila_INCLUDEPATH += \
$${fila_INCLUDEPATH} \

# libfila DEFINES
#
libfila_DEFINES += \
$${fila_DEFINES} \

########################################################################
# libfila OBJECTIVE_HEADERS
#
#libfila_OBJECTIVE_HEADERS += \
#$${FILA_SRC}/fila/base/Base.hh \

# libfila OBJECTIVE_SOURCES
#
#libfila_OBJECTIVE_SOURCES += \
#$${FILA_SRC}/fila/base/Base.mm \

########################################################################
# libfila HEADERS
#
libfila_HEADERS += \
$${FILA_SRC}/fila/base/Acquired.hpp \
$${FILA_SRC}/fila/base/Argv.hpp \
$${FILA_SRC}/fila/base/Attached.hpp \
$${FILA_SRC}/fila/base/Base.hpp \
$${FILA_SRC}/fila/base/Created.hpp \
$${FILA_SRC}/fila/base/Joined.hpp \
$${FILA_SRC}/fila/base/Locked.hpp \
$${FILA_SRC}/fila/base/Opened.hpp \
$${FILA_SRC}/fila/base/Ran.hpp \
$${FILA_SRC}/fila/base/Sleep.hpp \
$${FILA_SRC}/fila/base/Suspended.hpp \
$${FILA_SRC}/fila/base/Waited.hpp \
\
$${FILA_SRC}/fila/mt/apple/mach/Semaphore.hpp \
$${FILA_SRC}/fila/mt/apple/osx/Mutex.hpp \
$${FILA_SRC}/fila/mt/apple/osx/Process.hpp \
$${FILA_SRC}/fila/mt/apple/osx/Semaphore.hpp \
$${FILA_SRC}/fila/mt/apple/osx/Sleep.hpp \
$${FILA_SRC}/fila/mt/apple/osx/Thread.hpp \
$${FILA_SRC}/fila/mt/microsoft/windows/crt/Thread.hpp \
$${FILA_SRC}/fila/mt/microsoft/windows/Mutex.hpp \
$${FILA_SRC}/fila/mt/microsoft/windows/Process.hpp \
$${FILA_SRC}/fila/mt/microsoft/windows/Semaphore.hpp \
$${FILA_SRC}/fila/mt/microsoft/windows/Sleep.hpp \
$${FILA_SRC}/fila/mt/microsoft/windows/Thread.hpp \
$${FILA_SRC}/fila/mt/Mutex.hpp \
$${FILA_SRC}/fila/mt/os/Mutex.hpp \
$${FILA_SRC}/fila/mt/os/Os.hpp \
$${FILA_SRC}/fila/mt/os/Process.hpp \
$${FILA_SRC}/fila/mt/os/Semaphore.hpp \
$${FILA_SRC}/fila/mt/os/Sleep.hpp \
$${FILA_SRC}/fila/mt/os/Thread.hpp \
$${FILA_SRC}/fila/mt/posix/Mutex.hpp \
$${FILA_SRC}/fila/mt/posix/Process.hpp \
$${FILA_SRC}/fila/mt/posix/Semaphore.hpp \
$${FILA_SRC}/fila/mt/posix/Sleep.hpp \
$${FILA_SRC}/fila/mt/posix/Thread.hpp \
$${FILA_SRC}/fila/mt/Process.hpp \
$${FILA_SRC}/fila/mt/Semaphore.hpp \
$${FILA_SRC}/fila/mt/Sleep.hpp \
$${FILA_SRC}/fila/mt/Thread.hpp \
\
$${FILA_SRC}/fila/os/apple/osx/DLLibrary.hpp \
$${FILA_SRC}/fila/os/apple/osx/DLLibraryMain.hpp \
$${FILA_SRC}/fila/os/DLLibrary.hpp \
$${FILA_SRC}/fila/os/DLLibraryMain.hpp \
$${FILA_SRC}/fila/os/microsoft/windows/DLLibrary.hpp \
$${FILA_SRC}/fila/os/microsoft/windows/DLLibraryMain.hpp \
$${FILA_SRC}/fila/os/os/DLLibrary.hpp \
$${FILA_SRC}/fila/os/os/DLLibraryMain.hpp \
$${FILA_SRC}/fila/os/os/Os.hpp \
$${FILA_SRC}/fila/os/posix/DLLibrary.hpp \
$${FILA_SRC}/fila/os/posix/DLLibraryMain.hpp \
\
$${FILA_SRC}/fila/lib/Version.hpp \
$${FILA_SRC}/fila/lib/fila/Version.hpp \

# libfila SOURCES
#
libfila_SOURCES += \
$${FILA_SRC}/fila/base/Acquired.cpp \
$${FILA_SRC}/fila/base/Argv.cpp \
$${FILA_SRC}/fila/base/Attached.cpp \
$${FILA_SRC}/fila/base/Base.cpp \
$${FILA_SRC}/fila/base/Created.cpp \
$${FILA_SRC}/fila/base/Joined.cpp \
$${FILA_SRC}/fila/base/Locked.cpp \
$${FILA_SRC}/fila/base/Opened.cpp \
$${FILA_SRC}/fila/base/Ran.cpp \
$${FILA_SRC}/fila/base/Sleep.cpp \
$${FILA_SRC}/fila/base/Suspended.cpp \
$${FILA_SRC}/fila/base/Waited.cpp \
\
$${FILA_SRC}/fila/mt/os/Mutex.hpp \
$${FILA_SRC}/fila/mt/os/Os.hpp \
$${FILA_SRC}/fila/mt/os/Process.hpp \
$${FILA_SRC}/fila/mt/os/Semaphore.hpp \
$${FILA_SRC}/fila/mt/os/Sleep.hpp \
$${FILA_SRC}/fila/mt/os/Thread.hpp \
\
$${FILA_SRC}/fila/os/DLLibrary.cpp \
\
$${FILA_SRC}/fila/lib/fila/Version.cpp \

########################################################################
