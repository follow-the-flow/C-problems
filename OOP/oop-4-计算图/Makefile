CC = g++
CFLAGS = -g
DEPS = Value.h Operator.h calc.h
OBJ = main.o Operator.o
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

clean:
	rm *.o
	
