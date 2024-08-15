#ifndef CCC_GLOBALS_H
#define CCC_GLOBALS_H

#define OPCODE_COUNT 148

#include <stdint.h>

extern uint8_t prg_ram[0xffff];
extern uint8_t *pc;
extern uint8_t s;
extern uint8_t a, x, y;
extern uint8_t p;
extern uint8_t debug;

extern void (*eval_func[OPCODE_COUNT])();

#endif //CCC_GLOBALS_H
