#ifndef CCC_GLOBALS_H
#define CCC_GLOBALS_H

#define OPCODE_COUNT 56

extern unsigned char prg_ram[0xffff];
extern unsigned char *pc;
extern unsigned char *s;
extern unsigned char a, x, y;
extern unsigned char p;

extern void (*eval_func[OPCODE_COUNT])();

#endif //CCC_GLOBALS_H
