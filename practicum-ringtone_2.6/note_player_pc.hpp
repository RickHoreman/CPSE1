#ifndef _NOTE_PLAYER_PC_HPP
#define _NOTE_PLAYER_PC_HPP

#include "note_player.hpp"

// ===========================================================================
//
// simple note player for a speaker connected to windows pc
//
// ===========================================================================

class note_player_pc : public note_player {
public: 
   void play( const note & n ) override;
};

#endif
