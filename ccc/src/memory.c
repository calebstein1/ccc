#include <string.h>
#include "memory.h"
#include "cpu.h"

u8 prg_ram[0x10000];
u8 *pc = &prg_ram[0x8000];

u8
read_mem(u16 addr) {
	return prg_ram[addr];
}

u16
read_mem16(u16 addr) {
	u8 low = prg_ram[addr];
	u8 hi = prg_ram[addr + 1];
	return MAKE_WORD;
}

void
zmem(u16 addr) {
	prg_ram[addr] = 0;
}

void
write_mem(u16 addr, u8 val) {
	prg_ram[addr] = val;
}

void
write_mem16(u16 addr, u16 val) {
	u8 low = (u8)(val & 0xff);
	u8 hi = (u8)(val >> 0x10);
	prg_ram[addr] = low;
	prg_ram[addr + 1] = hi;
}

void
write_nmem(u16 addr, const u8 *val, u16 n) {
	memcpy(&prg_ram[addr], val, n);
}

void
inc_mem(u16 addr) {
	prg_ram[addr]++;
}

void
dec_mem(u16 addr) {
	prg_ram[addr]--;
}

void
add_mem(u16 addr, u8 val) {
	prg_ram[addr] += val;
}

void
subtr_mem(u16 addr, u8 val) {
	prg_ram[addr] -= val;
}

void
and_mem(u16 addr, u8 val) {
	prg_ram[addr] &= val;
}

void
or_mem(u16 addr, u8 val) {
	prg_ram[addr] |= val;
}

u8 *
get_ptr(u16 addr) {
	return &prg_ram[addr];
}
