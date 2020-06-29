#ifndef FILTER_H
#define FILTER_H
#include <systemc.h>
using namespace sc_core;

SC_MODUE(filter)
{
    sc_fifo_in<int> i1;
    sc_fifo_out<int> vo;

    SC_CTOR(filter);
    private:
    void filter_thread(void);
};
#endif
