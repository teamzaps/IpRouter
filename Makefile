CC=g++
CLAGS=-I.
DEPS = 

all: router

#$@ - what is before the colon
#$< - the first item after the colon
router.o: router.cc $(DEPS)
	$(CC) -g -c -o router.o router.cc -I.
	
util.o: util.cc $(DEPS)
	$(CC) -g -c -o util.o util.cc -I.
	
main.o: main.cc $(DEPS)
	$(CC) -g -c -o main.o main.cc -I.

router: router.o util.o main.o
	$(CC) -g -o router main.o util.o router.o -I. -lpthread -lpcap
	
clean: 
	rm -rf *.o router
