########################################################################
# Copyright (c) 1988-2019 $organization$
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
#   File: Makefile
#
# Author: $author$
#   Date: 4/6/2019
#
# generic Gcc Makefile for fila Shared Library libhello
########################################################################


#
# target
#
libhello_SLIBTARGET = libhello.${SLIBEXT}

########################################################################

#
# user c++ flags
#
libhello_USRCXXFLAGS += \
${fila_USRCXXFLAGS} \

#
# user defines
#
libhello_USRDEFINES += \
${fila_USRDEFINES} \

#
# user includes
#
libhello_USRINCLUDES += \
${fila_USRINCLUDES} \

#
# user libdirs
#
libhello_USRLIBDIRS += \
${fila_USRLIBDIRS} \

########################################################################

#
# Shared Library .c sources
#
#libhello_SLIB_C_SOURCES += \
#${FILA_SRC}/fila/base/Base.c \

#
# Shared Library .cc sources
#
#libhello_SLIB_CC_SOURCES += \
#${FILA_SRC}/fila/base/Base.cc \

#
# Shared Library .cxx sources
#
#libhello_SLIB_CXX_SOURCES += \
#${FILA_SRC}/fila/base/Base.cxx \

#
# Shared Library .cpp sources
#
libhello_SLIB_CPP_SOURCES += \
${FILA_SRC}/fila/app/console/libhello/DLLibraryExporter.cpp \
${FILA_SRC}/fila/app/console/libhello/DLLibraryMain.cpp \

#
# Shared Library .m sources
#
#libhello_SLIB_M_SOURCES += \
#${FILA_SRC}/fila/base/Base.m \

#
# Shared Library .mm sources
#
#libhello_SLIB_MM_SOURCES += \
#${FILA_SRC}/fila/base/Base.mm \


########################################################################

#
# Shared Library libraries
#
libhello_LIBS += \
${fila_LIBS}


