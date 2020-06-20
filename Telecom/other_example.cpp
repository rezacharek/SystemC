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
}

class fifo: public sc_channel,
            public write_if,
            public read_if
{
    private:
        enum e {max_elements=10};
        char data[max_elements];
        int num_elements, first;
        sc_event write_event,
                read_event;
        bool fifo_empty() {};
        bool fifo_full() {};

    public:
        fifo() : num_elements(0) , first(0);

        void write(char c)
        {
            if (fifo_full()) 
                wait(read_event);
            data[num_elements++] = c;
            write_event.notify();
        }

        void read(char &c)
        {
            if (fifo_empty()) 
                wait(write_event);
                c = data[first];
                --num_elements;
            read_event.notify();
        }

        void reset()
        {
            num_elements = first = 0;
        }

        int num_available() {
            return num_elements;
        }
};


SC_MODULE(producer)
{
    public:
        sc_port<write_if> out;
    
    SC_CTOR(producer)
    {
        SC_THREAD(main);
    }

    void main()
    {
        char c;
        while(true)
        {
            out.write(c);
        }
    }
};

SC_MODULE(consumer)
{
    public:
        sc_port<read_if> in;

    SC_CTOR(consumer)
    {
        SC_THREAD(main);
    }

    void main()
    {
        char c;
        while(true)
        {
            in.read(c);
        }
    }
};

SC_MODULE(top)
{
    public: 
        fifo afifo;
        producer *pproducer;
        consumer *pconsumer;
    SC_CTOR(top)
    {
        pproducer = new producer("Producer");
        pproducer->out(afifo);

        pconsumer = new producer("Consumer");
        pconsumer->in(afifo);
    }
}