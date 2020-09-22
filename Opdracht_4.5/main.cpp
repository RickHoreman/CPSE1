#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}
extern "C" void decompress();


int main( void ){	
    hwlib::wait_ms(1000);
    decompress();
}