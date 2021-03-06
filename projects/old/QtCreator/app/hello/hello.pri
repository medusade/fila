########################################################################
# Copyright (c) 1988-2016 $organization$
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
#   File: hello.pri
#
# Author: $author$
#   Date: 9/24/2016
########################################################################

hello_INCLUDEPATH += \
$${fila_INCLUDEPATH} \

hello_DEFINES += \
$${fila_DEFINES} \

########################################################################
hello_HEADERS += \
$${NADIR_SRC}/thirdparty/gnu/glibc/posix/execvpe.h \
$${NADIR_SRC}/nadir/base/array.hpp \
$${NADIR_SRC}/nadir/base/wrapped.hpp \

hello_SOURCES += \
$${NADIR_SRC}/thirdparty/gnu/glibc/posix/execvpe.c \
$${NADIR_SRC}/nadir/base/array.cpp \
$${NADIR_SRC}/nadir/base/wrapped.cpp \

########################################################################
hello_HEADERS += \
$${PATRONA_SRC}/patrona/cpp/xos/console/getopt/MainOpt.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/console/getopt/Main.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/console/Main.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/String.hpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Array.hpp \

hello_SOURCES += \
$${PATRONA_SRC}/patrona/cpp/xos/console/getopt/MainOpt.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/String.cpp \
$${PATRONA_SRC}/patrona/cpp/xos/base/Array.cpp \

########################################################################
hello_HEADERS += \
$${CRONO_SRC}/crono/console/getopt/MainOpt.hpp \
$${CRONO_SRC}/crono/console/getopt/Main.hpp \
$${CRONO_SRC}/crono/console/Main.hpp \

hello_SOURCES += \

########################################################################
hello_HEADERS += \
$${FILA_SRC}/fila/os/os/DLLibrary.hpp \
$${FILA_SRC}/fila/os/microsoft/windows/DLLibrary.hpp \
$${FILA_SRC}/fila/os/apple/osx/DLLibrary.hpp \
$${FILA_SRC}/fila/os/posix/DLLibrary.hpp \
$${FILA_SRC}/fila/os/DLLibrary.hpp \

hello_SOURCES += \
$${FILA_SRC}/fila/os/os/DLLibrary.cpp \

########################################################################
hello_HEADERS += \
$${FILA_SRC}/fila/mt/os/Process.hpp \
$${FILA_SRC}/fila/mt/microsoft/windows/Process.hpp \
$${FILA_SRC}/fila/mt/apple/osx/Process.hpp \
$${FILA_SRC}/fila/mt/posix/Process.hpp \
$${FILA_SRC}/fila/mt/Process.hpp \
$${FILA_SRC}/fila/mt/os/Thread.hpp \
$${FILA_SRC}/fila/mt/apple/osx/Thread.hpp \
$${FILA_SRC}/fila/mt/posix/Thread.hpp \
$${FILA_SRC}/fila/mt/Thread.hpp \
$${FILA_SRC}/fila/mt/apple/osx/Semaphore.hpp \
$${FILA_SRC}/fila/mt/apple/mach/Semaphore.hpp \
$${FILA_SRC}/fila/mt/os/Semaphore.hpp \
$${FILA_SRC}/fila/mt/Semaphore.hpp \
$${FILA_SRC}/fila/mt/apple/osx/Mutex.hpp \
$${FILA_SRC}/fila/mt/posix/Mutex.hpp \
$${FILA_SRC}/fila/mt/os/Mutex.hpp \
$${FILA_SRC}/fila/mt/Mutex.hpp \
$${FILA_SRC}/fila/mt/os/Os.hpp \
$${FILA_SRC}/fila/base/Suspended.hpp \
$${FILA_SRC}/fila/base/Ran.hpp \
$${FILA_SRC}/fila/base/Locked.hpp \
$${FILA_SRC}/fila/base/Acquired.hpp \
$${FILA_SRC}/fila/base/Joined.hpp \
$${FILA_SRC}/fila/base/Waited.hpp \
$${FILA_SRC}/fila/base/Opened.hpp \
$${FILA_SRC}/fila/base/Created.hpp \
$${FILA_SRC}/fila/base/Attached.hpp \
$${FILA_SRC}/fila/base/Base.hpp \
$${FILA_SRC}/fila/base/Argv.hpp \

hello_SOURCES += \
$${FILA_SRC}/fila/mt/microsoft/windows/Process.cpp \
$${FILA_SRC}/fila/mt/os/Thread.cpp \
$${FILA_SRC}/fila/mt/os/Semaphore.cpp \
$${FILA_SRC}/fila/mt/os/Mutex.cpp \
$${FILA_SRC}/fila/mt/os/Os.cpp \
$${FILA_SRC}/fila/base/Suspended.cpp \
$${FILA_SRC}/fila/base/Ran.cpp \
$${FILA_SRC}/fila/base/Locked.cpp \
$${FILA_SRC}/fila/base/Acquired.cpp \
$${FILA_SRC}/fila/base/Joined.cpp \
$${FILA_SRC}/fila/base/Waited.cpp \
$${FILA_SRC}/fila/base/Opened.cpp \
$${FILA_SRC}/fila/base/Created.cpp \
$${FILA_SRC}/fila/base/Attached.cpp \
$${FILA_SRC}/fila/base/Base.cpp \
$${FILA_SRC}/fila/base/Argv.cpp \

########################################################################
hello_HEADERS += \
$${FILA_SRC}/fila/console/getopt/MainOpt.hpp \
$${FILA_SRC}/fila/console/getopt/Main.hpp \
$${FILA_SRC}/fila/console/Main.hpp \
$${FILA_SRC}/fila/console/Main_main.hpp \
$${FILA_SRC}/fila/app/console/hello/Main.hpp \

hello_SOURCES += \
$${FILA_SRC}/fila/app/console/hello/Main.cpp \

########################################################################
hello_LIBS += \
$${fila_LIBS} \

