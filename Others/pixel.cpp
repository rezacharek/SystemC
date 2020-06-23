#include <systemc.h>

struct Pixel 
{
    int R;
    int G;
    int B;

    Pixel(int _i = 0, int _j = 0, int _k = 0): R(_i), G(_j), B(_k){}

    bool operator == (const Pixel &other) const
    {
        return (R == other.R) && (G == other.G) && (B == other.B);
    }

    friend ostream& operator << (ostream& o, const Pixel& P) 
    {
        o << P.R << " " << P.G << " " << P.B << endl;
        return o;
    }

};

//Test

int sc_main(int argc, char * argv[])
{
    sc_signal<Pixel> my_pixel;
    cout << "--> @" << sc_time_stamp() << "P = " << my_pixel << endl;
    my_pixel = Pixel(1,2,3);

    cout << "--> @" << sc_time_stamp() << "P = " << my_pixel << endl;

    sc_start(10, SC_NS);

    cout << "--> @" << sc_time_stamp() << "P = " << my_pixel << endl;

    return 0;
}