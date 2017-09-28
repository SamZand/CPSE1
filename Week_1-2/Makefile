#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := song.cpp
 
# header files in this project
HEADERS := lsp_player.hpp player.hpp 
# other places to look for files for this project
SEARCH  :=    
    
song.cpp: Makefile make_song.exe bond.txt     
	make_song "bond.txt" > song.cpp
 
make_song.exe: make_song.cpp 
	g++ make_song.cpp -o make_song.exe
	 
# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
