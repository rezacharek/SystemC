#include <fstream>
#include "datagen.h"

datagen::datagen(sc_module_name nm)
:sc_module(nm)
{
    SC_HAS_PROCESS(datagen);
    SC_THREAD(stim_thread);
}

void datagen::stim_thread(void)
{
    std::ifstream f1("image_in.txt");
    do {
        int data1;
        f1 >> data1;
        d1->write(data1);

    } while(!d1.eof);
}