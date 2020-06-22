#include <systemc.h>

class stack_write_if: virtual public sc_interface
{
    public:
        virtual bool nb_write(char) = 0;
        virtual void reset() = 0;
};

class stack_read_if: virtual public sc_interface
{
    public:
        virtual bool nb_read(char &) = 0;
};

class stack:
public sc_module,
public stack_write_if,
public stack_read_if
{
    private:
        char data[20];
        int top;        // pointer to top of stack
    
    public:
        stack(sc_module_name name): sc_module(name), top(0){}

        bool nb_write(char c)
        {
            if (top < 20)
            {
                data[top++] = c;
                return true;
            }
            return false;
        }

        void reset()
        {
            top = 0;
        }

        bool nb_read(char& c)
        {
            if (top > 0)
            {
                c = data[--top];
                return true;
            }
            return false;
        }      
};

class producer: public sc_module
{
    public:
        sc_port<stack_write_if> out;

    void do_writes()
    {
        int i = 0;
        char* TestString = "Hello, this is going to be reversed";
        while (true)
        {
            if (out->nb_write(TestString[i]))
            {
                cout << "W: " << TestString[i]  << endl;
                // << sc_time_stamp() << endl;
                i = (i+1) % 32;
            } else
            {
                out->reset();
            }
            
        }
    }

    SC_CTOR(producer)
    {
        SC_THREAD(do_writes);
        // sensitive << Clock.pos();
    }
};

class consumer: public sc_module
{
    public:
        sc_port<stack_read_if> in;
    
    void do_reads()
    {
        // wait();
        char c;
        if (in->nb_read(c))
        {
            cout << "Reading." << endl;
        }
    }

    SC_CTOR(consumer)
    {
        SC_THREAD(do_reads);
        // sensitive << Clock.pos();
    }
};

int sc_main(int argc, char * argv[])
{
    stack Stack1("S1");
    producer P1("P1");
    P1.out(Stack1);

    consumer C1("C1");
    C1.in(Stack1);

    sc_start();

    return 0;
}
