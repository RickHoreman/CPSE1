#include "hwlib.hpp"
#include "note_player_pc.hpp"

  
void note_player_pc::play( const note & n ){
   if( n.frequency == 0 ){
      hwlib::wait_us( n.duration );
      
   } else {
      auto half_period = 1'000'000 / ( 2 * n.frequency );    
      auto end = hwlib::now_us() + n.duration;
      std::cout << n.frequency << "\n";
      do { 
         hwlib::wait_us( half_period );
         hwlib::wait_us( half_period );
      } while ( end > hwlib::now_us() );
   }     
}
