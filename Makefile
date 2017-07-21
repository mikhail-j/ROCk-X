#
# Makefile for external AMDGPU modules
#
# Copyright (C) 2017 Qijia (Michael) Jin
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

export CONFIG_HSA_AMD=m
export CONFIG_DEBUG_FS=y

external_mod_amdkfd:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell cd amd/amdkfd && pwd)

clean_amdkfd:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell cd amd/amdkfd && pwd) clean

external_mod_amdkcl:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell cd amd/amdkcl && pwd)

clean_amdkcl:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell cd amd/amdkcl && pwd) clean
