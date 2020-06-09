#include <systemc.h>

SC_MODULE(foo)
{
    sc_in<bool> clk;
    sc_in<bool> rst;
    sc_out<sc_uint<8> > data;

    SC_CTOR(foo):clk("clk"), data("data")
    {
        cout 
            << "module: " << name()         << endl 
            << "clk:    " << clk.name()     << endl 
            << "rst:    " << rst.name()     << endl
            << "data:   " << data.name()    << endl;

    }
};

int sc_main(int argc, char * argv[]){
    foo bar("foobar");
    return 0;
}