#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################
gcc := g++
ln := "..\..\i686-7.3.0-release-posix-dwarf-rt_v5-rev0\mingw32/bin/g++"
# source files in this project (main.cpp is automatically assumed)
SOURCES := decompress.asm compressed.asm

# header files in this project
HEADERS := 

# other places to look for files for this project
SEARCH  := 

compressed.asm: encoder.exe
	./encoder.exe

encoder.exe : encoder.o
	$(ln) encoder.o -o encoder.exe

encoder.o : encoder.cpp compressor.hpp
	$(gcc) -c encoder.cpp -o encoder.o

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
