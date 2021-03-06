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
#   File: fila.pri
#
# Author: $author$
#   Date: 9/24/2016
########################################################################
FILA_PKG = ../../../../..
FILA_BLD = ../..

FILA_PRJ = $${FILA_PKG}
FILA_BIN = $${FILA_BLD}/bin
FILA_LIB = $${FILA_BLD}/lib
FILA_SRC = $${FILA_PKG}/src

CONFIG(debug, debug|release) {
FILA_CONFIG = Debug
fila_DEFINES += DEBUG_BUILD
} else {
FILA_CONFIG = Release
fila_DEFINES += RELEASE_BUILD
}
fila_DEFINES += BUILD_CONFIG=$${FILA_CONFIG}

########################################################################
# NO Qt
QT -= gui core

########################################################################
# patrona
PATRONA_PKG = $${FILA_PKG}/../patrona
PATRONA_PRJ = $${PATRONA_PKG}
PATRONA_SRC = $${PATRONA_PKG}/src

patrona_INCLUDEPATH += \
$${PATRONA_SRC} \

patrona_DEFINES += \

patrona_LIBS += \

########################################################################
# nadir
NADIR_PKG = $${FILA_PKG}/../nadir
NADIR_PRJ = $${NADIR_PKG}
NADIR_SRC = $${NADIR_PKG}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \

nadir_LIBS += \

########################################################################
# crono
CRONO_PKG = $${FILA_PKG}/../crono
CRONO_PRJ = $${CRONO_PKG}
CRONO_SRC = $${CRONO_PKG}/src

crono_INCLUDEPATH += \
$${CRONO_SRC} \

crono_DEFINES += \

crono_LIBS += \

########################################################################
fila_INCLUDEPATH += \
$${FILA_SRC} \
$${crono_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \

fila_DEFINES += \

########################################################################
fila_LIBS += \
-L$${FILA_LIB}/libfila \
-lfila \
