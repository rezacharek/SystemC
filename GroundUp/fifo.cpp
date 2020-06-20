#include <systemc.h>


class write_if : public sc_interface
{
    public:
        virtual void write(char) = 0;
        virtual void reset() = 0;
};

class read_if : public sc_interface
{
    public:
        virtual void read(char&) = 0;
        virtual int num_available() = 0;
};

class fifo :    public sc_channel, 
                public write_if, 
                public read_if
{
    private:
        enum e {max_elements = 10};
        char data[max_elements];
        int num_elements, first;
        sc_event write_event, read_event;

        bool fifo_empty() {};
        bool fifo_full() {};

        public:
            fifo(sc_module_name name): sc_channel(name), num_elements(0), first(0){}

            void write(char c)
            {
                if (fifo_full())
                {
                    wait(read_event);
                }
                data[num_elements++] = c;
                write_event.notify();
            }

            void read(char &c)
            {
                if (fifo_empty())
                {
                    wait(write_event);
                }
                c = data[first];
                --num_elements;
                first = num_elements - 1;
                read_event.notify();

            }

            void reset()
            {
                num_elements = first = 0;
            }

            int num_available()
            {
                return num_elements;
            }
};


class producer : public sc_module
{
    public:
        sc_port<write_if> out;

        SC_HAS_PROCESS(producer);

        producer(sc_module_name name): sc_module(name)
        {
            SC_THREAD(main);
        }

        void main()
        {
            char c;
            while(true)
            {
                out->write(c);
            }
        }
};

class consumer: public sc_module
{
    public:
        sc_port<read_if> in;
        SC_HAS_PROCESS(consumer);

        consumer(sc_module_name name): sc_module(name)
        {
            SC_THREAD(main);
        }
        void main()
        {
            char c;
            while(true)
            {
                in->read(c);
            }
        }
};

class top : public sc_module
{
    public:
        fifo *afifo;
        producer *prod;
        consumer *cons;

    top(sc_module_name name): sc_module(name)
    {
        afifo = new fifo("FIFO");
        prod = new producer("Producer");
        prod->out(afifo);

        cons = new consumer("Consumer");
        cons->in(afifo);
    }
};


int sc_main(int argc, char * argv[])
{
    top top1("Top1");
    sc_start();
    return 0;
}
