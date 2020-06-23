SRCS = nan.cpp
EXEC = nan
OBJS = $(SRCS:.cpp=.o)
DIR = /usr/local

all : $(EXEC)
		@echo Executable produit: $(EXEC)

$(EXEC) : $(OBJS)
		g++ -L$(DIR)/lib $(OBJS) -lsystemc -o $(EXEC)

.cpp.o :
		g++ -c -I$(DIR)/include $<

clean:
		-rm -i *.o *~