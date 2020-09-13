#include "note_player_pc.hpp"
#include <iostream>
#include <fstream>
#include "note.hpp"
using namespace std;
  
void note_player_pc::play( const note & n ){
ofstream MyFile;
   MyFile.open("song.hpp", ofstream::app);
   MyFile <<"      p.play( note {" << n.frequency << ", "<< n.duration <<"});\n";
   MyFile.close();
}  
