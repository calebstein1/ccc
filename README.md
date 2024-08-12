# Caleb's Crappy Console

Caleb's Crappy Console is a new fantasy console under heavy development and coming soon.

Unlike other fantasy consoles that aim to be easy to use by running languages like Lua, this console runs it's own custom virtual 8-bit CPU that's somewhat reminiscent of the 6502.
There's currently no documentation on its machine code or assembly language, though obviously that'll change as the project moves along.
Ultimately, it would be nice to properly implement the 6502 instruction set in this thing, that way you'd be able to write software for it using, for example, the cc65 toolchain.
We'll call it a stretch goal 🤷

## Status by project

#### CCC (Caleb's Crappy Console)

Builds and runs, currently the STA, STX, STY, LDA, LDX, LDY, INC, INX, INY, DEC, DEX, and DEY instructions are implemented.

#### CCA (Caleb's Crappy Assembler)

Exceedingly crappy.

This is the result of about an hour of work because I got tired of raw-dogging hexadecimal into binary files to test the console.
It will turn .ccasm files (Caleb's Crappy Assembly Language) into CCC machine code and that's it.
No fancy features, but it makes testing easier for now.
In the end, it will get a ground-up rewrite, or I'll just implement 6502 properly and not have to worry about this wierd custom assembler.
