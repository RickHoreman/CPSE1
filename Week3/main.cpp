#include "hwlib.hpp"
#include "sine_lookup.hpp"
#include <ctime>

int main( void ){	 
    hwlib::wait_ms(100);

    namespace target = hwlib::target;
   
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );

    auto minuteButton = target::pin_in(target::pins::d2);
    auto hourButton = target::pin_in(target::pins::d3);
   
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   
    auto w = hwlib::glcd_oled( i2c_bus, 0x3c );  
     
    w.clear();
    w.flush();

    constexpr auto coords = xy_clock_lookup();

    int startTime = hwlib::now_us() / 1000000;

    int minuteOffset = 0;

    while(true){
        w.clear();
        for( int i=0; i < 12; i++){
            auto circle = hwlib::circle(coords.get_edge(i), 2);
            circle.draw(w);
        }
        if(!minuteButton.read()){
            minuteOffset++;
        }
        if(!hourButton.read()){
            minuteOffset += 60;
        }
        int currentTime = hwlib::now_us() / 1000000;
        int secPassed = currentTime - startTime;
        int minutesPassed = secPassed/60 + minuteOffset;
        auto minutes = hwlib::line(hwlib::xy(64,32), coords.get_minutes((minutesPassed+45)%60));
        auto hours = hwlib::line(hwlib::xy(64,32), coords.get_hours((minutesPassed/12+45)%60));
        minutes.draw(w);
        hours.draw(w);
        w.flush();
    }
}