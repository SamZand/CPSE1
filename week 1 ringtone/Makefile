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

song.cpp: Makefile play_creater.exe          
	play_creater "Van Halen-Eruption:d=32,o=5,b=120:c#6,16c#,e,g#,16c#,e,g#,16c#,e,g#,16c#,e,c#6,16c#,e,g#,16c#,e,g#,16c#,e,g#,16c#,e,a,16c#,e,a,16c#,e,a,16c#,e,a,16c#,e,a,16c#,e,a,16c#,e,a,16c#,e,a,16c#,d#,a,16d#,f#,a,16d#,f#,a,16d#,f#,a,16d#,f#,a,16d#,f#,a,16d#,f#,b,16d#,f#,b,16d#,f#,b,16e,g#,b,16e,g#,b,16e,g#,b,16e,g#,b,16e,g#,b,16e,g#,b,16e,g#,b,16e,g#,c6,16e,g,b,16e,g,b,16e,g,b,16e,g,b,16e,g,b,16e,g,d6,16e,g,d6,16e,f#,d6,16f#,a,d6,16f#,a,d6,16f#,a,d6,16f#,a,d6,16f#,a,d6,16f#,a,e6,16f#,a,e6,16f#,a,e6,16b,g#,e6,16b,g#,e6,16b,g#,e6,16b,g#,e6,16b,g#,e6,b,16g#,e6,b,16g#,e6,b,16g#,e6,16g#.,e6,g#,16b,e6,16b.,e6,b,16d6,e6,a#,16c#6,e6,a#,16c#6,e6,a,16c6,e6,a,16c6,e6,g#,16b,e6,g#,b,d6,e6,b,16d6,e6,b,16d6,e6,a#,16c#6,e6,a#,16c#6,e6,a,16c6,e6,a,16c6,e6,g#,16b,e6,g#,16b,d6,a,16c6,d6,a,16c6,d6,g#,16b,d6,g#,16b,d6,g,16a#,d6,g,16a#,d6,f#,a,16d6,f#,a,16c6,g,16a#,c6,g,16a#,c6,f#,16a,c6,f#,16a,c6,f,16g#,c6,f,16g#,c6,e,16g,c6,e,16g,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,e,16g,b,e,16g,b,e,16g,b,e,16g,b,e,16g,b,e,16g,b,e,16g,b,e,16g,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,d#,16f#,b,e,16g,b,d#,16f#,b,e,16g,b,d#,16f#,b,e,16g,b,d#,16f#,b,e,16g,b,d#,16f#,b,e,16g,b,d#,16f#,b,e,16g,b,d#,16f#,b,e,16g,b,d#,16f#,b,e,16g,b,d#,16f#,b,4e,4a#4,4e.3" > song.cpp
   
play_creater.exe: play_creater.cpp
	g++ play_creater.cpp -o play_creater.exe

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due
