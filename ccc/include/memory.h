#ifndef CCC_MEMORY_H
#define CCC_MEMORY_H

#include "fixed.h"

extern u8 *pc;

u8 read_mem(u16 addr);
u16 read_mem16(u16 addr);
void zmem(u16 addr);
void write_mem(u16 addr, u8 val);
void write_mem16(u16 addr, u16 val);
void write_nmem(u16 addr, const u8 *val, u16 n);
void inc_mem(u16 addr);
void dec_mem(u16 addr);
void add_mem(u16 addr, u8 val);
void subtr_mem(u16 addr, u8 val);
void and_mem(u16 addr, u8 val);
void or_mem(u16 addr, u8 val);
u8 *get_ptr(u16 addr);

#endif /* CCC_MEMORY_H */
