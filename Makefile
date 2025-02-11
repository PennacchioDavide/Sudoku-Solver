all: program

exe:
	mkdir -p exe

exe/main.o: src/main.c | exe
	gcc -c -o exe/main.o src/main.c

exe/utilities.o: src/utilities.c | exe
	gcc -c -o exe/utilities.o src/utilities.c

exe/solver.o: src/solver.c | exe
	gcc -c -o exe/solver.o src/solver.c

FILEO = exe/main.o exe/utilities.o exe/solver.o

program: $(FILEO)
	gcc -o main $(FILEO)

clean:
	rm -f main exe/*.o