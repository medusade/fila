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
# generic Gcc Makefile for fila Executable hello
########################################################################


#
# target
#
hello_EXETARGET = hello

########################################################################

#
# user c++ flags
#
hello_USRCXXFLAGS += \
${fila_USRCXXFLAGS} \

#
# user defines
#
hello_USRDEFINES += \
${fila_USRDEFINES} \

#
# user includes
#
hello_USRINCLUDES += \
${fila_USRINCLUDES} \

#
# user libdirs
#
hello_USRLIBDIRS += \
${fila_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
hello_EXE_C_SOURCES += \
${NADIR_SRC}/thirdparty/gnu/glibc/posix/execvpe.c \

#
# Executable .cc sources
#
#hello_EXE_CC_SOURCES += \
#${FILA_SRC}/fila/base/Base.cc \

#
# Executable .cxx sources
#
#hello_EXE_CXX_SOURCES += \
#${FILA_SRC}/fila/base/Base.cxx \

#
# Executable .cpp sources
#
hello_EXE_CPP_SOURCES += \
${FILA_SRC}/fila/mt/os/Process.cpp \
${FILA_SRC}/fila/app/console/hello/Main.cpp \

#
# Executable .m sources
#
#hello_EXE_M_SOURCES += \
#${FILA_SRC}/fila/base/Base.m \

#
# Executable .mm sources
#
#hello_EXE_MM_SOURCES += \
#${FILA_SRC}/fila/base/Base.mm \


########################################################################

#
# Executable libraries
#
hello_LIBS += \
${fila_LIBS}



