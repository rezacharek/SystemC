#include <systemc.h>
 
int sc_main (int argc, char * argv[])
{
   sc_time T(0.333, SC_NS);
 
   sc_signal<int> i;
   int j = 0;
 
   cout << "init: " << sc_time_stamp() << " j = " << j <<" et i = " << i << endl;
 
   i = 33;
   j = 33;
   cout << "--> @ " << sc_time_stamp() << " j = " << j <<" et i = " << i << endl;
 
   sc_start(T);
   cout << "--> @ " << sc_time_stamp() << " j = " << j <<" et i = " << i << endl;
 
   i = 44;
   j = 44;
   cout << "--> @ " << sc_time_stamp() << " j = " << j <<" et i = " << i << endl;
 
   sc_start(SC_ZERO_TIME);
   cout << "--> @ " << sc_time_stamp() << " j = " << j <<" et i = " << i << endl;
 
   return 0;
}