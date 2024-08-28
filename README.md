# Caleb's Crappy Console

Caleb's Crappy Console is a new fantasy console under heavy development and coming soon.

Unlike other fantasy consoles that aim to be easy to use by running languages like Lua, this console runs it's own custom virtual 8-bit CPU that's based on the design of the 6502 CPU.
It is binary compatible with 6502 machine code and will run binaries produced by the cc65 toolchain using the included ld65 config file.

## Current Status

All documented 6502 instructions are implemented.
All addressing modes are supported with the exception of the indirect modes, which will be added soon.

There is a display which can currently display a solid color background that can be changed by writing bytes to addresses 0x2002, 0x2003, and 0x2004 (r, g, and b respectively), as well as 8x8 sprites.
CCC uses 2bbp sprite sheets, supporting four colors per sprite (one of which being transparent).
Sprite sheets are 128x512 pixels, supporting up to 1023 8x8 sprites (sprite 0 is always an empty sprite slot).
Currently, the best tool for drawing sprites for CCC is [YY-CHR](https://w.atwiki.jp/yychr/), though this will be replaced by the official CCC devkit soon.

Six input buttons are supported, the status of which can be accessed via a bitfield at address 0x4001 (the bottom six bits correspond to primary, secondary, left, right, up, and down respectively from low to high; a bit is set while the button is pressed and unset when the button is not).

There is a basic shell which can be used as part of debugging (invoked by default with the `brk` instruction) supporting `peek` and `poke` to view and manipulate the memory of a running program.
The default `brk` handler can be overridden by writing a new address (little endian) to bytes 0xfffe and 0xffff.
The default `brk` handler is located at 0x7ff8-0x7fff, the 8 bytes preceding the program start, and is loaded by the CPU during its initial boot.

## Building the console

CCC depends on SDL2 for its display and input handling.

Once you've installed SDL2, the next thing you'll do is clone the repo and enter the directory:

```
git clone https://github.com/calebstein1/ccc
cd ccc
```

You can then build CCC as so:

```
cd ccc
make
```

If you'd like to build CCLib as well, you'll need to install the [cc65 toolchain](https://cc65.github.io/) (you'll need to install it to build programs anyway, unless you like writing machine code 😉) and then you'd do as follows:

```
cd lib
ca65 cclib.s
```

## Building programs

#### This documentation is probably inadiquate to take you through actually building a program, proper documentation will be available on the official site when that launches

### Assembly without CCLib

```
ca65 your-file.s
ld65 -C [/path/to/ccc/ld65/ccc.conf] -o your-file.bin your-file.o
```

### Assembly with CCLib

At the top of your program source, you'll need to import any functions you're using from CCLib as so:

```
.import waitnextframe, printbuff, printnum
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

### Building the Finished Cartridge

CCC carts are currently structured with the first 32k being the program, the next 16k being the sprite data, the following 256 bytes being the custom four color palettes.
This is subject to change once tilemaps are introduced, as that will need a space in the cart as well.

Carts are currently assembled using the `cat` command as so:

```
cat [/path/to/program.bin] [/path/to/spritesheet.chr] [/path/to/palette.pal] > [your-cart.cart]
```

This is not an ideal workflow and there is a `mkcart` utility under development.
