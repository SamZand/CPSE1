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
HEADERS := player.hpp lsp_player.hpp
     
# other places to look for files for this project
SEARCH  :=     
     
song.cpp: Makefile Make_song.exe   
	Make_song "Bond:d=4,o=5,b=320:c,8d,8d,d,2d,c,c,c,c,8d#,8d#,2d#,d,d,d,c,8d,8d,d,2d,c,c,c,c,8d#,8d#,d#,2d#,d,c#,c,c6,1b.,g,f,1g." > song.cpp

Make_song.exe: Make_song.cpp
	g++ Make_song.cpp -o Make_song.exe
	
# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
