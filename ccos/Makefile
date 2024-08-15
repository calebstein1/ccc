SRC = $(wildcard ./*.asm)
CCA = ../cca/bin/cca

all: clean ccos

clean:
	rm -f *.bin
	rm -f *.txt

ccos: $(SRC)
	$(CCA) $< -os
