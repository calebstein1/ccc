#ifndef CCC_GLOBALS_H
#define CCC_GLOBALS_H

#define CCC_VER "0.0.1-prealpha"
#define OPCODE_COUNT 189

#include <stdint.h>

extern uint8_t prg_ram[0x10000];
extern uint8_t *pc;
extern uint8_t s;
extern uint8_t a, x, y;
extern uint8_t p;

extern uint8_t prg_loaded;

extern void (*eval_func[OPCODE_COUNT])();

#endif //CCC_GLOBALS_H
