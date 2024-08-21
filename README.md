# Caleb's Crappy Console

Caleb's Crappy Console is a new fantasy console under heavy development and coming soon.

Unlike other fantasy consoles that aim to be easy to use by running languages like Lua, this console runs it's own custom virtual 8-bit CPU that's based on the design of the 6502 CPU.
It is binary compatible with 6502 machine code and will run binaries produced by the cc65 toolchain using the included ld65 config file.

## Current Status

All documented 6502 instructions are implemented.
All addressing modes are supported with the exception of the indirect modes, which will be added soon.
There is no display support yet, but strings and numbers can be printed to the console.
There is a basic shell which can be used as part of debugging (invoked with `ccc [prg.bin] -d`) supporting `peek` and `poke` to view and manipulate the memory of a running program.

## Building the program

First thing you should do is clone the repo and enter the directory:

```
git clone https://github.com/calebstein1/ccc
cd ccc
```

You can then build CCC as so:

```
cd ccc
make
```

If you'd like to build CCLib as well, you'll need to install the [cc65 toolchain](https://cc65.github.io/) and then you'd do as follows:

```
cd lib
ca65 cclib.s
```

## Building programs

### Assembly without CCLib

```
ca65 your-file.s
ld65 -C [/path/to/ccc/ld65/ccc.conf] -o your-file.bin your-file.o
```

### Assembly with CCLib

At the top of your program source, you'll need to import any functions you're using from CCLib as so:

```
.import printbuff, printnum
```

Then:

```
ca65 your-file.s
ld65 -C [/path/to/ccc/ld65/ccc.conf] -o your-file.bin your-file.o [path/to/cclib.o]
```

### C (experimental support, currently no standard library for CCC)

```
cc65 your-file.c
ca65 your-file.s
ld65 -C [/path/to/ccc/ld65/ccc.conf] -o your-file.bin your-file.o none.lib
```
