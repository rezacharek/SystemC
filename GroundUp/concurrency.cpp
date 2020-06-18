#include <systemc.h>

SC_MODULE(two_processes){
    void wiper_thread()
    {   
        auto time = 0 ;
        while(time < 10000)
        {
            std::cout << "Wiping left" << std::endl;
            wait(500,SC_MS);
            std::cout << "Wiping right" << std::endl;
            wait(500,SC_MS);
            time += 1000;  
        }
    }
    void blinker_thread()
    {   
        auto blinker = true;
        auto time = 0;
        while(time < 10000)
        {   
            blinker = true;
            std::cout << "Blink ON" << std::endl;
            wait(300, SC_MS);
            cout << "Blink OFF" << std::endl;
            blinker = false;
            wait(300, SC_MS);
            time += 600;
        }
    }

    SC_CTOR(two_processes)
    {
        SC_THREAD(wiper_thread);
        SC_THREAD(blinker_thread);
    }
};

int sc_main(int argc, char * argv[])
{   two_processes my("my");
    sc_start();
    return 0;
}