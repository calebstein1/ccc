#include <stdio.h>

#include "fixed.h"
#include "console.h"
#include "memory.h"
#include "cpu.h"

void
print_buffer(void) {
	printf("%s", get_ptr(0x4020));
}

void
print_number(void) {
	u8 low = read_mem(0x4020);
	u8 hi = read_mem(0x4021);
	printf("%d\n", MAKE_WORD);
}

