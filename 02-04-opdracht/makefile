#============================================================================
#
# simple project makefile (just a main file)
#
# (c) Wouter van Ooijen (wouter@voti.nl) 2017
#
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at 
# http://www.boost.org/LICENSE_1_0.txt) 
#
#============================================================================

# source & header files in this project (main.cpp is automatically assumed)                                                                                                                                                                   

HEADERS += note.hpp
HEADERS += melody.hpp
HEADERS += note_player.hpp
HEADERS += fur_elise.hpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

HEADERS += note_printer.hpp
SOURCES += note_printer.cpp

HEADERS += file_printer.hpp
SOURCES += file_printer.cpp

HEADERS += rtttl_player.hpp
SOURCES += rtttl_player.cpp

# set RELATIVE to the next higher directory 
# and defer to the appropriate Makefile.* there
RELATIVE := ..
include $(RELATIVE)/makefile.native