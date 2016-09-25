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
$${FILA_SRC}/fila/mt/apple/osx/Mutex.hpp \
$${FILA_SRC}/fila/mt/posix/Mutex.hpp \
$${FILA_SRC}/fila/mt/os/Mutex.hpp \
$${FILA_SRC}/fila/mt/Mutex.hpp \
$${FILA_SRC}/fila/mt/os/Os.hpp \
$${FILA_SRC}/fila/base/Locked.hpp \
$${FILA_SRC}/fila/base/Acquired.hpp \
$${FILA_SRC}/fila/base/Joined.hpp \
$${FILA_SRC}/fila/base/Waited.hpp \
$${FILA_SRC}/fila/base/Created.hpp \
$${FILA_SRC}/fila/base/Attached.hpp \
$${FILA_SRC}/fila/base/Base.hpp \

hello_SOURCES += \
$${FILA_SRC}/fila/mt/os/Mutex.cpp \
$${FILA_SRC}/fila/mt/os/Os.cpp \
$${FILA_SRC}/fila/base/Locked.cpp \
$${FILA_SRC}/fila/base/Acquired.cpp \
$${FILA_SRC}/fila/base/Joined.cpp \
$${FILA_SRC}/fila/base/Waited.cpp \
$${FILA_SRC}/fila/base/Created.cpp \
$${FILA_SRC}/fila/base/Attached.cpp \
$${FILA_SRC}/fila/base/Base.cpp \

########################################################################
hello_HEADERS += \
$${FILA_SRC}/fila/console/Main.hpp \
$${FILA_SRC}/fila/console/Main_main.hpp \
$${FILA_SRC}/fila/app/console/hello/Main.hpp \

hello_SOURCES += \
$${FILA_SRC}/fila/app/console/hello/Main.cpp \

########################################################################
hello_LIBS += \
$${fila_LIBS} \

