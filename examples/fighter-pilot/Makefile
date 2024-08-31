TARGET = bin/fighter-pilot.cart
SRC = $(wildcard src/*.s)
OBJ = $(patsubst src/%.s, obj/%.o, $(SRC))
BIN = $(patsubst src/%.s, obj/%.bin, $(SRC))
AS = ca65
LD = ld65

all: clean $(TARGET)

clean:
	rm -f obj/*.o
	rm -f bin/*

$(TARGET): $(BIN)
	cat $? content/fighter-pilot.chr content/p.pal > $@

$(BIN): $(OBJ)
	mkdir -p bin
	$(LD) -C ../../ld65/ccc.cfg -o $@ $? ../../lib/cclib.o

obj/%.o: src/%.s
	mkdir -p obj
	$(AS) -o $@ $<

