#include <systemc.h>

SC_MODULE(ordered_events)
{
    SC_CTOR(ordered_events)
    {
        SC_THREAD(B_thread);
        SC_THREAD(A_thread);
        SC_THREAD(C_thread);
    }

    void A_thread()
    {   auto time = 0;
        while(time < 200)
        {
            a_event.notify(SC_ZERO_TIME);
            std::cout << "A sent a_event!" << std::endl;
            wait(c_event);
            std::cout << "A got c_event" << std::endl;
            time += 100;
        }
    }

    void B_thread()
    {
        auto time = 0;
        while(time < 200)
        {
            b_event.notify(SC_ZERO_TIME);
            std::cout << "B sent b_event!" << std::endl;
            wait(a_event);
            std::cout << "B got a_event" << std::endl;
            time += 100;
        }
    }

    void C_thread()
    {
        auto time = 0;
        while(time < 200)
        {
            c_event.notify(SC_ZERO_TIME);
            std::cout << "C sent c_event!" << std::endl;
            wait(b_event);
            cout << "C got b_event!" << std::endl;
            time += 100;
        }
    }
    sc_event a_event, b_event, c_event;
};

int sc_main(int argc, char * argv[])
{
    ordered_events events("events");
    sc_start();
    wait(1,SC_MS);
    sc_stop();
    return 0;
}