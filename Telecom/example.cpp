#include <systemc.h>

SC_MODULE(A)
{
    sc_in<bool> in;

    SC_CTOR(A):in("in")
    {
        SC_METHOD (trigger);
        dont_initialize();
        sensitive << in;
    }

    void trigger()
    {
        cout << name() << ": triggered @" << sc_time_stamp() << endl;
    }
};


SC_MODULE (C)
{
    sc_export <sc_signal<bool> > inter;

    SC_CTOR(C): inter("inter"), sig("sig")
    {
        inter(sig);
        SC_THREAD(test);
        sig = false;
    }

    void test()
    {
       for(int i=0; i<9;i++) {
          wait(15, SC_NS);
          sig = !sig;
       }
       sc_stop();
    }

   private:
    sc_signal <bool> sig;

};

int sc_main(int argc, char* argv[])
{
    A a("a");
    C c("c");

    a.in(c.inter);

    cout
       << "let's start..." << endl
       <<  "Initial: " << c.inter->read()
       << endl;

    sc_start ();
    cout << "...done" << endl
       <<  "Final: " << c.inter->read()
       << endl;

    return 0;
}