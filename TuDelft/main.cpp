#include "top.h"

int exit_status = 0; // global

int sc_main(int argc, char *argv[])
{
    top top_i("top_i");
    sc_start(1000,SC_NS);

    if( ! sc_end_of_simulation_invoked())
    {
        sc_stop();
    }

    return exit_status;
}