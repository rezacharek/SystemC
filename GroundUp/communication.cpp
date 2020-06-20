#include <systemc.h>
using namespace std;

class MyInterface
{
    public:
    virtual void hello() = 0;
    // virtual void hello2();
};

class SimpleImpl: virtual public MyInterface
{
    public:
        virtual void hello() override
        {
            cout << "Hi " << endl;
        }
};

class CplxImpl: virtual public MyInterface 
{   
    public:
        virtual void hello() override
        {
            cout << "Hi " << message << endl;
        }
        CplxImpl(string s): message(s) {}
    private:
        const string message;
};


int main()
{
    MyInterface * o[2];
    o[0] = new SimpleImpl();
    o[1] = new CplxImpl("folks");

    for (int i = 0; i < 2; i++)
    {
        o[i] -> hello();
    }

    return 0;
}