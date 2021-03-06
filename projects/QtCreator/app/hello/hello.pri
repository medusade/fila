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
#   File: hello.pri
#
# Author: $author$
#   Date: 12/25/2018
#
# QtCreator .pri file for fila executable hello
########################################################################

########################################################################
# hello

# hello TARGET
#
hello_TARGET = hello

# hello INCLUDEPATH
#
hello_INCLUDEPATH += \
$${fila_INCLUDEPATH} \

# hello DEFINES
#
hello_DEFINES += \
$${fila_DEFINES} \

########################################################################
# hello OBJECTIVE_HEADERS
#
#hello_OBJECTIVE_HEADERS += \
#$${FILA_SRC}/fila/base/Base.hh \

# hello OBJECTIVE_SOURCES
#
#hello_OBJECTIVE_SOURCES += \
#$${FILA_SRC}/fila/base/Base.mm \

########################################################################
# hello HEADERS
#
hello_HEADERS += \
$${NADIR_SRC}/thirdparty/gnu/glibc/posix/execvpe.h \
$${FILA_SRC}/fila/mt/os/Process.hpp \
$${FILA_SRC}/fila/app/console/hello/Main.hpp \

# hello SOURCES
#
hello_SOURCES += \
$${NADIR_SRC}/thirdparty/gnu/glibc/posix/execvpe.c \
$${FILA_SRC}/fila/mt/os/Process.cpp \
$${FILA_SRC}/fila/app/console/hello/Main.cpp \

########################################################################
# hello FRAMEWORKS
#
hello_FRAMEWORKS += \
$${fila_FRAMEWORKS} \

# hello LIBS
#
hello_LIBS += \
$${fila_LIBS} \


