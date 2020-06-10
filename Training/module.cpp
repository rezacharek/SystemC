#include <systemc>

using namespace sc_core;
SC_MODULE(MODULE_A) 
{
    SC_CTOR(MODULE_A)
    {
        std::cout << name() << " constructor" << std::endl;
    }
};

struct MODULE_B : public sc_module
{
    SC_CTOR(MODULE_B)
    {
        std::cout << name() << " constructor" << std::endl;
    }
};

class MODULE_C : public sc_module 
{
    public:
        SC_CTOR(MODULE_C)
        {
            std::cout << name() << " constructor" << std::endl;
        }
};


int sc_main(int, char*[])
{
    MODULE_A module_a("module_a");

    MODULE_B module_b("modb");

    MODULE_C module_c("module_c");

    sc_start();

    return 0;
}