SRCS = identifiantsdes fichiers sources
EXEC = identifiantpour l'executable produit
OBJS =$(SRCS:.cpp=.o)
DIR = chemin d'accesa l'installation de SystemC

all : $(EXEC)
	@echo Executable produit : $(EXEC)

$(EXEC) : $(OBJS)
	g++ -L$(DIR)/lib-linux64$(OBJS) -lsystemc -o $(EXEC)

.cpp.o : 
	g++ -c -I$(DIR)/include $<

clean:-rm -i *.o *~ 