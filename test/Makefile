CPP = g++.exe
CC = gcc.exe
LD = dllwrap.exe
BIN = Modules.exe
MODS = mod.dll

.PHONY: all modules

all: $(BIN) $(MODS)
	

modules: $(MODS)
	

$(BIN): main.o Modules.o
	$(CPP) main.o Modules.o -o Modules.exe

main.o: main.cpp Modules.h
	$(CPP) -c main.cpp -o main.o

Modules.o: Modules.cpp Modules.h
	$(CPP) -c Modules.cpp -o Modules.o

mod.dll: mod.o mod.def
	$(LD) mod.o --def mod.def -o mod.dll

mod.o: mod.c
	$(CC) -fPIC -c mod.c -o mod.o

clean:
	@-rm *.o

distclean: clean
	@-rm Modules Modules.exe mod.dll mod.so
