#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "wave-signal.h"
#include <math.h>


int main (int argc, char * argv[]) 
{
    struct system_wave_signal sws;

    system_wave_signal_init( &sws );
    system_wave_signal_uset( &sws, 20.0/65536*158, 25600, 512 );
    system_wave_signal_iset( &sws, 20.0/65536*10, 25600, 512 );

    wave_signal_add( &sws.u_a, 230, 0, 50, 0 );
    wave_signal_add( &sws.u_a, 10, 0, 50*50, 0 );
    wave_signal_add( &sws.u_b, 230, 0, 50, 240 );
    wave_signal_add( &sws.u_c, 230, 0, 50, 120 );

    wave_signal_add( &sws.i_a, 5, 0, 50, 30+0 );
    wave_signal_add( &sws.i_b, 5, 0, 50, 30+240 );
    wave_signal_add( &sws.i_c, 5, 0, 50, 30+120 );

    printf( "ua=%f\n", wave_signal_get_rms( &sws.u_a) );
    system_wave_signal_write_csv( &sws, "abc.csv" );
    
    system_wave_signal_destroy( &sws );
    return 0;
}