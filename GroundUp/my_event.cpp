#include <systemc.h>


class write_: virtual public sc_interface
{   public:
    virtual void count(int) = 0;
};

class read_: virtual public sc_interface
{   public:
    virtual void decount(int) = 0;
};

class merger:   public sc_channel,
                public write_,
                public read_
{
    private:
        sc_event written_event, read_event;
    public:
        merger(sc_module_name name): sc_channel(name) {}
    
        void count(int num)
        {  

            if(num >= 10)
            {
                wait(read_event);
            }
            num += 1;
            written_event.notify();
            cout << "Count: " << num << endl;
            

        }

        void decount(int num)
        {
            if(num < 10)
            {
                wait(written_event);
            }
            num -= 1;
            read_event.notify();
            cout << "Decount: " << num << endl;
            
        }
};

class producer: public sc_module
{
    public:
        sc_port<write_> out;

        SC_HAS_PROCESS(producer);

        producer(sc_module_name name) : sc_module(name)
        {
            SC_THREAD(main);
        }

        void main()
        {   
            int num = 0;
                for(int i = 0; i < 10; i++)
                {
                    out->count(num);
                }
        }
};

class consumer: public sc_module
{
    public:
        sc_port<read_> in;

        SC_HAS_PROCESS(consumer);

        consumer(sc_module_name name) : sc_module(name)
        {
            SC_THREAD(main);
        }

        void main()
        {
            int num;
            for(int i = 0; i < 10; i++)
            {
                in->decount(num);
            }
        }
};

class top : public sc_module
{
    public:
        merger *my_merge;
        producer *prod;
        consumer *cons;
    
        top(sc_module_name name): sc_module(name)
        {
            my_merge = new merger("my");
            prod = new producer("Producer");
            prod->out(*my_merge);

            cons = new consumer("Consumer");
            cons->in(*my_merge);
        }
};


int sc_main(int argc, char * argv [])
{
    top Top("My_top");
    sc_start();
    return 0;
}