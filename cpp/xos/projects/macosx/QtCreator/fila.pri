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
#   Date: 8/6/2017
#
# macosx QtCreator .pri file for fila
########################################################################

FILA_OS = macosx
#QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS += -std=c++0x

########################################################################
# rostra
ROSTRA_BLD = $${OTHER_BLD}/$${ROSTRA_PKG}/build/$${FILA_OS}/QtCreator/$${BUILD_CONFIG}
ROSTRA_LIB = $${ROSTRA_BLD}/lib

rostra_LIBS += \
-L$${ROSTRA_LIB}/librostra \
-lrostra \

########################################################################
# nadir
NADIR_BLD = $${OTHER_BLD}/$${NADIR_PKG}/build/$${FILA_OS}/QtCreator/$${BUILD_CONFIG}
NADIR_LIB = $${NADIR_BLD}/lib

nadir_LIBS += \
-L$${NADIR_LIB}/libnadir \
-lnadir \

########################################################################
# patrona
PATRONA_BLD = $${OTHER_BLD}/$${PATRONA_PKG}/build/$${FILA_OS}/QtCreator/$${BUILD_CONFIG}
PATRONA_LIB = $${PATRONA_BLD}/lib

patrona_LIBS += \
-L$${PATRONA_LIB}/libpatrona \
-lpatrona \

########################################################################
# crono
CRONO_BLD = $${OTHER_BLD}/$${CRONO_PKG}/build/$${FILA_OS}/QtCreator/$${BUILD_CONFIG}
CRONO_LIB = $${CRONO_BLD}/lib

crono_LIBS += \
-L$${CRONO_LIB}/libcrono \
-lcrono \

########################################################################
fila_INCLUDEPATH += \

fila_DEFINES += \

########################################################################
fila_LIBS += \
$${crono_LIBS} \
$${nadir_LIBS} \
$${build_fila_LIBS} \
-lpthread \
-ldl \
