#ifndef DATAGEN_H
#define DATAGEN_H
#include <systemc.h>
using namespace sc_core;

SC_MODULE(datagen)
{
    sc_fifo_out <int> d1;

    void stim_thread(void);

    SC_CTOR(datagen);
};