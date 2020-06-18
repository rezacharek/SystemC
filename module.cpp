#include <systemc.h>

SC_MODULE(foo)
{
    sc_in<bool> i;
    SC_CTOR(foo) 
    {
        cout << i.name() << endl;
    }
};

SC_MODULE(bar)
{
    sc_out<bool> o;
    SC_CTOR(bar) 
    {
        cout << o.name() << endl;
    }
};

int sc_main(int argc, char * argv[])
{
    sc_signal<bool> s;
    foo foo_i("foo_i");
    bar bar_i("bar_i");

    foo_i.i(s);
    bar_i.o(s);
    
}