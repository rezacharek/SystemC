#include <systemc.h>

SC_MODULE(missing_event)
{
    sc_event a_event;
    
    SC_CTOR(missing_event)
    {
        SC_THREAD(B_thread);
        SC_THREAD(A_thread);
        SC_THREAD(C_thread);
    }

    void A_thread()
    {
        a_event.notify();
        std::cout << "A sent a_event!" << std::endl;
    }

    void B_thread()
    {
        wait(a_event);
        std::cout << "B got a_event!" << std::endl;
    }

    void C_thread()
    {
        wait(a_event);
        std::cout << "C got a_event!" << std::endl;
    }

};

int sc_main(int argc, char * argv [])
{
    missing_event ev("ev");
    sc_start();

    return 0;
}