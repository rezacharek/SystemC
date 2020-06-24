SRCS = ../models/pv_dma.cpp ../models/pv_memory.cpp dma_testbench.cpp main.cpp
EXEC = simudma
OBJS = $(SRCS:.cpp=.o)
# FLAGS = -DPV_MEMORY_DEBUG -DPV_DMA_DEBUG -DPV_ROUTER_DEBUG -DPV_DMA_BLOCK_TRANSFER 
DIR = /usr/local
DIRTLM = /usr/local

all : $(EXEC)
	@echo The executable is: $(EXEC)

$(EXEC) : $(OBJS)
	g++ -L$(DIR)/lib $(OBJS) -lsystemc -o $(EXEC)

.cpp.o : 
	g++ -c -I$(DIR)/include -I$(DIRTLM)/include -I../models -I../protocol $< -o $@

clean:	
	-rm *.o *~ ../models/*.o ../models/*~