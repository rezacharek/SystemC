#include <systemc.h>

class tag_write_if : virtualpublicsc_interface
{
    public:
        virtual void write(sc_uint<8> i) =0;
};