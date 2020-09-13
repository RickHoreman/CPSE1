#include "hwlib.hpp"
#include "note_player_pc.hpp"
#include <fstream>
#include <iostream>
  
void note_player_pc::play( const note & n ){
   std::ofstream song;
   song.open("song.hpp", std::ofstream::app);
   song << "      p.play( note{ " << n.frequency <<", " << n.duration << " } );\n";
   song.close();
}
