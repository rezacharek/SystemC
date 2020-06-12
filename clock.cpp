#include <systemc.h>

int sc_main(int argc, char * argv[])
{
    sc_clock ck1("ck1", 10, SC_NS);

    cout << ck1 << endl;
    sc_start(5, SC_NS);
    cout << ck1 << endl;
    sc_start(2, SC_NS);
    cout << ck1 << endl;

}