# Caleb's Crappy Console

Caleb's Crappy Console is a new fantasy console under heavy development and coming soon.

Unlike other fantasy consoles that aim to be easy to use by running languages like Lua, this console runs it's own custom virtual 8-bit CPU that's somewhat reminiscent of the 6502.
There's currently no documentation on its machine code or assembly language, though obviously that'll change as the project moves along.
Ultimately, it would be nice to properly implement the 6502 instruction set in this thing, that way you'd be able to write software for it using, for example, the cc65 toolchain.
We'll call it a stretch goal 🤷

## Status by project

#### CCC (Caleb's Crappy Console)

Builds and runs, currently working towards getting all opcodes implemented.

#### CCA (Caleb's Crappy Assembler)

Assembles .asm files into .bin files for execution on the CCC CPU.

Right now, CCC assembly is a very limited subset of 6502 assembly.
Not every opcode is implemented yet, but that's in progress.
Supported addressing modes are immediate, absolute, absolute indexed, zero-page, and zero-page indexed.
There is currently no support for indirect addressing.
Labels are supported for use with branching instructions, JMP, and JSR.
Any CCC assembly code should run on a proper 6502, but 6502 assembly won't run on CCC.

#### CCOS (Caleb's Crappy Operating System)

Currently just initializes CCC's registers and stack pointer, it will ultimately contain something akin to a "standard library" of subroutines for programs to use.

The top 256 bytes of CCC's memory are reserved for CCOS, and after it's finished initializing the system, execution is handed to the loaded program at 0x8000.
