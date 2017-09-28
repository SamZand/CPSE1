#include "note.hpp"

#ifndef player_hpp
#define player_hpp

class player {
public:   
   virtual void play( const note & n ) = 0;
};

#endif
