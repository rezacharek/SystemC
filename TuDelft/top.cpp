#include "top.h"
#include "datagen.h"
#include "filter.h"
#include "checker.h"
using namespace sc_core;

top::top(sc_module_name inst)
:sc_module(inst),
gen(new datagen("gen")),
med(new filter("med")),
chk(new checker("chk"))
{

    gen->d1(c1);
    med->i1(c1);
    med->vo(chk->c3);

}