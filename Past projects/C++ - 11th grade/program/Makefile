

all: calc


Context.o: Context.cc context.hh Operation.hh
Calc.o: Calc.cc Calc.hh context.hh Operation.hh
main.o: Main.cc Calc.hh context.hh Operation.hh
BinOperations.o: BinOperations.cc BinOperations.hh Operation.hh context.hh
UnOperations.o: UnOperations.cc UnOperations.hh Operation.hh context.hh
MacroOperation.o: MacroOperation.cc MacroOperation.hh Operation.hh context.hh
calc: Main.o Calc.o Context.o BinOperations.o UnOperations.o MacroOperation.o
	g++ Main.o Calc.o Context.o BinOperations.o UnOperations.o MacroOperation.o -o calc

clean:
	rm -f *.o *~ calc
