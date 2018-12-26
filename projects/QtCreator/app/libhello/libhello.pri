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
#   File: libhello.pri
#
# Author: $author$
#   Date: 12/26/2018
#
# QtCreator .pri file for fila executable libhello
########################################################################

########################################################################
# libhello

# libhello TARGET
#
libhello_TARGET = libhello
libhello_TEMPLATE = lib

# libhello INCLUDEPATH
#
libhello_INCLUDEPATH += \
$${fila_INCLUDEPATH} \

# libhello DEFINES
#
libhello_DEFINES += \
$${fila_DEFINES} \

########################################################################
# libhello OBJECTIVE_HEADERS
#
#libhello_OBJECTIVE_HEADERS += \
#$${FILA_SRC}/fila/base/Base.hh \

# libhello OBJECTIVE_SOURCES
#
#libhello_OBJECTIVE_SOURCES += \
#$${FILA_SRC}/fila/base/Base.mm \

########################################################################
# libhello HEADERS
#
libhello_HEADERS += \
$${FILA_SRC}/fila/os/posix/DLLibraryMain.hpp \
$${FILA_SRC}/fila/os/apple/osx/DLLibraryMain.hpp \
$${FILA_SRC}/fila/os/DLLibraryMain.hpp \
$${FILA_SRC}/fila/app/console/libhello/DLLibraryExporter.hpp \
$${FILA_SRC}/fila/app/console/libhello/DLLibraryMain.hpp \

# libhello SOURCES
#
libhello_SOURCES += \
$${FILA_SRC}/fila/app/console/libhello/DLLibraryExporter.cpp \
$${FILA_SRC}/fila/app/console/libhello/DLLibraryMain.cpp \

########################################################################
# libhello FRAMEWORKS
#
libhello_FRAMEWORKS += \
$${fila_FRAMEWORKS} \

# libhello LIBS
#
libhello_LIBS += \
$${fila_LIBS} \

