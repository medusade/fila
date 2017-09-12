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
#   Date: 9/9/2017
#
# QtCreator .pri file for fila executable fila
########################################################################

fila_exe_TARGET = fila

########################################################################
fila_exe_INCLUDEPATH += \
$${fila_INCLUDEPATH} \

fila_exe_DEFINES += \
$${fila_DEFINES} \

########################################################################
# patrona
fila_exe_HEADERS += \
$${PATRONA_SRC}/xos/base/logged.hpp \
$${PATRONA_SRC}/xos/base/opened.hpp \
$${PATRONA_SRC}/xos/base/created.hpp \
$${PATRONA_SRC}/xos/base/attached.hpp \
$${PATRONA_SRC}/xos/base/acquired.hpp \

fila_exe_SOURCES += \
$${PATRONA_SRC}/xos/base/logged.cpp \
$${PATRONA_SRC}/xos/base/opened.cpp \
$${PATRONA_SRC}/xos/base/created.cpp \
$${PATRONA_SRC}/xos/base/attached.cpp \
$${PATRONA_SRC}/xos/base/acquired.cpp \

########################################################################
# fila
fila_exe_HEADERS += \
$${FILA_SRC}/xos/mt/os/semaphore.hpp \
$${FILA_SRC}/xos/mt/apple/osx/semaphore.hpp \
$${FILA_SRC}/xos/mt/apple/mach/semaphore.hpp \
$${FILA_SRC}/xos/mt/semaphore.hpp \
$${FILA_SRC}/xos/mt/os/mutex.hpp \
$${FILA_SRC}/xos/mt/apple/osx/mutex.hpp \
$${FILA_SRC}/xos/mt/posix/mutex.hpp \
$${FILA_SRC}/xos/mt/mutex.hpp \
$${FILA_SRC}/xos/mt/os/os.hpp \
$${FILA_SRC}/xos/console/mt/logger/main_main.hpp \

fila_exe_SOURCES += \
$${FILA_SRC}/xos/mt/os/semaphore.cpp \
$${FILA_SRC}/xos/mt/os/mutex.cpp \
$${FILA_SRC}/xos/mt/os/os.cpp \
$${FILA_SRC}/xos/console/mt/logger/main_main.cpp \

########################################################################
fila_exe_LIBS += \
$${fila_LIBS} \



