#include <systemc.h>

int sc_main(int argc, char * argv[]){
    // Pointer on the file that genererates tracing
    sc_trace_file *trace_f;

    trace_f = sc_create_vcd_trace_file ("my_simu_trace");

    trace_f->set_time_unit(1,SC_NS);

    int t = 0;

    sc_trace(trace_f, t, "t");
    for(int i = 0; i < atoi(argv[1]); i++){
        sc_start(10, SC_NS);
        i += 1;


    }

    sc_start(10, SC_NS);

    sc_close_vcd_trace_file(trace_f);

    return 0;



}