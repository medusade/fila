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
# Os Gcc Makefile for fila Shared Library libhello
########################################################################

PKG = ../../../../../..

BMK = build/Makefile/Gcc
MAK = projects/Makefile/Gcc
PRJ = projects/os/Makefile/Gcc
SRC = src

include $(PKG)/$(BMK)/Makedefines
include $(PKG)/$(MAK)/Makedefines
include $(PKG)/$(MAK)/Makefile
include $(PKG)/$(BMK)/Makefile
include $(PKG)/$(MAK)/app/libhello/Makefile

#
# target
#
SLIBTARGET = ${libhello_SLIBTARGET}

########################################################################

#
# user defines
#
USRDEFINES += \
${libhello_USRDEFINES}

#
# user includes
#
USRINCLUDES += \
${libhello_USRINCLUDES}

#
# user libdirs
#
USRLIBDIRS += \
${libhello_USRLIBDIRS}

#
# user c++ flags
#
USRCXXFLAGS += \
${libhello_USRCXXFLAGS}

#
# user c flags
#
USRCFLAGS += \
${libhello_USRCFLAGS}

#
# user ld flags
#
USRLDFLAGS += \
${libhello_USRLDFLAGS}

########################################################################

#
# Shared Library C sources
#
SLIB_C_SOURCES += \
${libhello_SLIB_C_SOURCES}

#
# Shared Library C++ .cc sources
#
SLIB_CC_SOURCES += \
${libhello_SLIB_CC_SOURCES}

#
# Shared Library C++ .cxx sources
#
SLIB_CXX_SOURCES += \
${libhello_SLIB_CXX_SOURCES}

#
# Shared Library C++ .cpp sources
#
SLIB_CPP_SOURCES += \
${libhello_SLIB_CPP_SOURCES}

#
# Shared Library Objective C .m sources
#
SLIB_M_SOURCES += \
${libhello_SLIB_M_SOURCES}

#
# Shared Library Objective C++ .mm sources
#
SLIB_MM_SOURCES += \
${libhello_SLIB_MM_SOURCES}

########################################################################

#
# Shared Library libraries
#
LIBS += \
${libhello_LIBS}

########################################################################

#
# Shared Library depends
#
#SLIBDEP += \
#$(PKG)/$(BLD)/libsomelib \
#
SLIBDEP += \

#
# Shared Library depend dirs
#
#SLIBDEP_DIRS += \
#../libsomelib
#
SLIBDEP_DIRS += \

include $(PKG)/$(MAK)/Makerules

#
# Shared Library depend rules
#
#$(PKG)/$(BLD)/libsomelib.a:
#	@(echo Building libsomelib.a ...;\
#	  pushd ../libsomelib;\
#	  ((make) || (exit 1));\
#	  popd)
#

