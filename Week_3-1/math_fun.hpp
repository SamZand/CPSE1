#include "hwlib.hpp"

#ifndef math_fun_hpp
#define math_fun_hpp

constexpr double pow( double g, int n ){
   return ( n < 1 ) ? 1 : g * pow( g, n - 1 ); 
}    

constexpr double fac( int n ){ 
   return ( n < 2 ) ? 1 : n * fac( n - 1 ); 
}

constexpr double taylor( double a, int n ){
    return ( n < 0 ) ? 0 : pow( a, n ) / fac( n ) - taylor( a, n - 2 );
}

constexpr double sin( double a ){
   return taylor( a, 17 );
}

constexpr double radians_from_degrees( int degrees ){
   return 2 * 3.14 * ( degrees / 360.0 );
}

constexpr int scaled_sine_from_degrees( int degrees, int scale ){
   return scale * sin( radians_from_degrees( degrees ));
}

constexpr int scaled_cosine_from_degrees( int degrees, int scale ){
   return scale * sin( radians_from_degrees( degrees - 90 ));
}
#endif