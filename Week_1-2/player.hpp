#include "note.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP

// ===========================================================================
//
// interface for a note player
//
// ===========================================================================

class player {
public:   
   virtual void play( const note & n ) = 0;
};

#endif // PLAYER_HPP
