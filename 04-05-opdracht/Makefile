rm := del -f

SOURCES := compressed.asm decompress.asm
HEADERS := match.hpp compressor.hpp decompressor.hpp

SEARCH  := ../04-library

customclean: clean
	$(rm) *exe *o compressed.asm

compressed.asm: compressed.asm compressor
	./compressor

compressor: compressor.cpp match.hpp compressor.hpp wilhelmus.txt
	g++ -std=c++17 compressor.cpp -o compressor

RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due