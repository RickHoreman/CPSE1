#ifndef _SINE_LOOKUP_HPP
#define _SINE_LOOKUP_HPP
#include "hwlib.hpp"

constexpr float power(float base, int exp) {
    if(exp == 0){
        return 1;
    }
    if(exp == 1){
        return base;
    }
    return base * power(base, exp - 1);
}

constexpr float fact(float n) {
    return n <= 0 ? 1 : n * fact(n-1);
}


constexpr float sine(float deg){
    float rad = (deg * 3.14159) / 180;
    float sin = 0;


    sin = rad - (power(rad, 3) / fact(3)) + (power(rad, 5) / fact(5)) - (power(rad, 7) / fact(7)) + (power(rad, 9) / fact(9)) - (power(rad, 11) / fact(11)) + (power(rad, 13) / fact(13)) - (power(rad, 15) / fact(15)) + (power(rad, 17) / fact(17));
    return sin;
}

constexpr int root(int low, int high, int N) {
    if (low <= high) {
        int mid = (low + high) / 2;
        
        if ((mid * mid <= N) && ((mid + 1) * (mid + 1) > N)) {
            return mid;
        }

        else if (mid * mid < N) {
            return root(mid + 1, high, N);
        } else {
            return root(low, mid - 1, N);
        }
    }
    return low;
}

/*class sine_lookup {
private:       
    float values[ 360 ] = {};
public: 
    constexpr sine_lookup(){
        for( int i = 0; i < 360; i++ ){
            values[ i ] = sine( i );
        }
    }
    constexpr float get( int n )const{
        return values[ n ];
    }
};*/

class xy_clock_lookup {
private:       
    hwlib::xy edge[ 12 ] = {};
    hwlib::xy minutes[ 60 ] = {};
    hwlib::xy hours[ 60 ] = {};
public: 
    constexpr xy_clock_lookup(){
        int rEdge = 25;
        int rMinutes = 20;
        int rHours = 15;
        for( int i = 0; i < 12; i++ ){
            edge[i].y = 32 + (sine(i*30) * rEdge);
            int temp = power(rEdge, 2) - (sine(i*30) * rEdge)*(sine(i*30) * rEdge);
                        
            if(i<3 || i>8){
                edge[i].x = 64 + root(0, temp, temp);
            }
            else{
                edge[i].x = 64 - root(0, temp, temp);
            }
        }
        for( int i = 0; i < 60; i++ ){
            minutes[i].y = 32 + (sine(i*6) * rMinutes);
            int temp = power(rMinutes, 2) - (sine(i*6) * rMinutes)*(sine(i*6) * rMinutes);
            if(i<15 || i>44){
                minutes[i].x = 64 + root(0, temp, temp);
            }
            else{
                minutes[i].x = 64 - root(0, temp, temp);
            }
            hours[i].y = 32 + (sine(i*6) * rHours);
            int temp2 = power(rHours, 2) - (sine(i*6) * rHours)*(sine(i*6) * rHours);
            if(i<15 || i>44){
                hours[i].x = 64 + root(0, temp2, temp2);
            }
            else{
                hours[i].x = 64 - root(0, temp2, temp2);
            }
        }
        
    }
    constexpr hwlib::xy get_edge( int n )const{
        return edge[ n ];
    }
    constexpr hwlib::xy get_minutes( int n )const{
        return minutes[ n ];
    }
    constexpr hwlib::xy get_hours( int n )const{
        return hours[ n ];
    }
};

#endif