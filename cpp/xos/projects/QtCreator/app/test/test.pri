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
#   File: test.pri
#
# Author: $author$
#   Date: 8/6/2017
########################################################################

test_TARGET = test

test_INCLUDEPATH += \
$${fila_INCLUDEPATH} \

test_DEFINES += \
$${fila_DEFINES} \

########################################################################
# nadir
test_HEADERS += \
$${NADIR_SRC}/xos/logger/Interface.hpp \
$${NADIR_SRC}/xos/base/std/StringBase.hpp \
$${NADIR_SRC}/xos/base/StringBase.hpp \
$${NADIR_SRC}/xos/base/CharsBase.hpp \
$${NADIR_SRC}/xos/base/Exception.hpp \
$${NADIR_SRC}/xos/base/Base.hpp \
$${NADIR_SRC}/xos/console/IO.hpp \
$${NADIR_SRC}/xos/console/Main.hpp \
$${NADIR_SRC}/xos/console/Main_main.hpp \
$${NADIR_SRC}/xos/app/console/hello/Main.hpp \

test_SOURCES += \
$${NADIR_SRC}/xos/logger/Interface.cpp \
$${NADIR_SRC}/xos/base/Exception.cpp \
$${NADIR_SRC}/xos/base/StringBase.cpp \
$${NADIR_SRC}/xos/base/CharsBase.cpp \
$${NADIR_SRC}/xos/base/Base.cpp \
$${NADIR_SRC}/xos/console/IO.cpp \

_test_SOURCES += \
$${NADIR_SRC}/xos/app/console/hello/Main.cpp \
$${NADIR_SRC}/xos/console/Main.cpp \
$${NADIR_SRC}/xos/console/Main_main.cpp \

########################################################################
# patrona
test_HEADERS += \
$${PATRONA_SRC}/xos/base/Created.hpp \
$${PATRONA_SRC}/xos/base/Attached.hpp \
$${PATRONA_SRC}/xos/base/Acquired.hpp \
$${PATRONA_SRC}/xos/base/Locked.hpp \
$${PATRONA_SRC}/xos/base/Logged.hpp \

test_SOURCES += \
$${PATRONA_SRC}/xos/base/Created.cpp \
$${PATRONA_SRC}/xos/base/Acquired.cpp \
$${PATRONA_SRC}/xos/base/Attached.cpp \
$${PATRONA_SRC}/xos/base/Locked.cpp \
$${PATRONA_SRC}/xos/base/Logged.cpp \

########################################################################
# fila
test_HEADERS += \
$${FILA_SRC}/xos/mt/os/Semaphore.hpp \
$${FILA_SRC}/xos/mt/apple/osx/Semaphore.hpp \
$${FILA_SRC}/xos/mt/apple/mach/Semaphore.hpp \
$${FILA_SRC}/xos/mt/Semaphore.hpp \
$${FILA_SRC}/xos/mt/os/Mutex.hpp \
$${FILA_SRC}/xos/mt/apple/osx/Mutex.hpp \
$${FILA_SRC}/xos/mt/posix/Mutex.hpp \
$${FILA_SRC}/xos/mt/Mutex.hpp \
$${FILA_SRC}/xos/mt/os/Os.hpp \
$${FILA_SRC}/xos/app/console/mt/hello/Main.hpp \
$${FILA_SRC}/xos/app/console/mt/hello/MainOpt.hpp \
$${FILA_SRC}/fila/app/console/mt/hello/Main.hpp \
$${FILA_SRC}/fila/app/console/mt/hello/MainOpt.hpp \
$${FILA_SRC}/xos/console/mt/getopt/Main.hpp \
$${FILA_SRC}/xos/console/mt/getopt/MainOpt.hpp \
$${FILA_SRC}/xos/console/mt/Main.hpp \
$${FILA_SRC}/fila/console/mt/getopt/Main.hpp \
$${FILA_SRC}/fila/console/mt/getopt/MainOpt.hpp \
$${FILA_SRC}/fila/console/mt/Main.hpp \
$${FILA_SRC}/xos/console/mt/Locked.hpp \
$${FILA_SRC}/xos/console/mt/Main_main.hpp \

test_SOURCES += \
$${FILA_SRC}/xos/mt/os/Semaphore.cpp \
$${FILA_SRC}/xos/mt/os/Mutex.cpp \
$${FILA_SRC}/xos/mt/os/Os.cpp \
$${FILA_SRC}/xos/app/console/mt/hello/Main.cpp \
$${FILA_SRC}/xos/app/console/mt/hello/MainOpt.cpp \
$${FILA_SRC}/xos/console/mt/Locked.cpp \
$${FILA_SRC}/xos/console/mt/Main_main.cpp \

_test_HEADERS += \

_test_SOURCES += \
$${FILA_SRC}/xos/console/mt/Main.cpp \
$${FILA_SRC}/xos/app/console/mt/hello/Main.cpp \

########################################################################
test_LIBS += \
$${fila_LIBS} \
