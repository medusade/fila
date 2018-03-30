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
#   File: libhello.pri
#
# Author: $author$
#   Date: 10/24/2016
########################################################################

libhello_INCLUDEPATH += \
$${fila_INCLUDEPATH} \

libhello_DEFINES += \
$${fila_DEFINES} \

########################################################################
libhello_HEADERS += \
$${FILA_SRC}/fila/app/console/libhello/DLLibraryMain.hpp \
$${FILA_SRC}/fila/os/apple/osx/DLLibraryMain.hpp \
$${FILA_SRC}/fila/os/posix/DLLibraryMain.hpp \
$${FILA_SRC}/fila/os/DLLibraryMain.hpp \

libhello_SOURCES += \
$${FILA_SRC}/fila/app/console/libhello/DLLibraryMain.cpp \

########################################################################
libhello_LIBS += \
$${fila_LIBS} \

