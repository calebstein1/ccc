#include <stdio.h>

#include "fixed.h"
#include "console.h"
#include "cpu.h"

void
print_buffer(void) {
    printf("%s", &prg_ram[0x4020]);
}

void
print_number(void) {
    printf("%d\n", (u16)(prg_ram[0x4020] + (prg_ram[0x4021] ? prg_ram[0x4021] * 0x100 : 0)));
}

