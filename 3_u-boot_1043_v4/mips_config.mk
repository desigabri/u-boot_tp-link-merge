#
# (C) Copyright 2003
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# Copyright (c) 2013 Qualcomm Atheros, Inc.
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

PLATFORM_CPPFLAGS += -DCONFIG_MIPS -D__MIPS__

#When compiling the assemble source code, it will 
#miss these options if we use gcc-4.6.1
PLATFORM_CPPFLAGS += -mabicalls -fpic

ifeq ($(FLASH_TYPE),S25FL128P)
   PLATFORM_CPPFLAGS += -D$(FLASH_TYPE)
endif
