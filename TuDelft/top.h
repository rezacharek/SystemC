#ifndef TOP_H
#define TOP_H
#include <systemc.h>
using namespace sc_core;

struct datagen;
struct filter;
struct checker;

SC_MODULE(top)
{
    SC_CTOR(top);
    private:
        // Fifo Channels
        sc_fifo<int>  c1;
        sc_fifo<int>  c2;

        // Declare modules
        datagen* gen;
        filter* med;
        checker* chk;
};