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
#   File: fila.pri
#
# Author: $author$
#   Date: 3/24/2018
#
# QtCreator .pri file for fila executable fila
########################################################################

########################################################################
# fila

# fila_exe TARGET
#
fila_exe_TARGET = fila

# fila_exe INCLUDEPATH
#
fila_exe_INCLUDEPATH += \
$${fila_INCLUDEPATH} \

# fila_exe DEFINES
#
fila_exe_DEFINES += \
$${fila_DEFINES} \

########################################################################
# fila_exe OBJECTIVE_HEADERS
#
#fila_exe_OBJECTIVE_HEADERS += \
#$${FILA_SRC}/fila/base/Base.hh \

# fila_exe OBJECTIVE_SOURCES
#
#fila_exe_OBJECTIVE_SOURCES += \
#$${FILA_SRC}/fila/base/Base.mm \

########################################################################
# fila_exe HEADERS
#
fila_exe_HEADERS += \
$${FILA_SRC}/fila/console/Main_main.hpp \

# fila_exe SOURCES
#
fila_exe_SOURCES += \
$${FILA_SRC}/fila/console/Main_main.cpp \

########################################################################
# fila_exe FRAMEWORKS
#
fila_exe_FRAMEWORKS += \
$${fila_FRAMEWORKS} \

# fila_exe LIBS
#
fila_exe_LIBS += \
$${fila_LIBS} \


