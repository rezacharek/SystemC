#include <systemc.h>

SC_MODULE(one)
{
    sc_in<bool> i;
    SC_CTOR(one) {}
}

SC_MODULE(two)
{
    sc_out<bool> o;
    SC_CTOR(two) {}
}

int sc_main(int argc, char * argv[])
{
    sc_signal<bool> s;

    one in_signal;
    two out_signal;
}