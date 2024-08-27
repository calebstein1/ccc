#ifndef CCC_EVAL_H
#define CCC_EVAL_H

#include "opcodes.h"

/* Function prototypes */
#define X(opcode, op_fn, str_lit) void op_fn(void);
OPCODES_LIST
#undef X

#endif /* CCC_EVAL_H */
