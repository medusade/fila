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
#   File: libhello.pro
#
# Author: $author$
#   Date: 12/26/2018
#
# QtCreator .pro file for fila executable libhello
########################################################################
include(../../../../../build/QtCreator/fila.pri)
include(../../../../QtCreator/fila.pri)
include(../../fila.pri)
include(../../../../QtCreator/app/libhello/libhello.pri)

TARGET = $${libhello_TARGET}
TEMPLATE = $${libhello_TEMPLATE}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libhello_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libhello_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libhello_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libhello_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libhello_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libhello_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${libhello_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${libhello_LIBS} \
$${FRAMEWORKS} \

