#ifndef CCC_MEMORY_H
#define CCC_MEMORY_H

#include "fixed.h"

extern u8 *pc;

u8 read_mem(u16 addr); /* Read an 8-bit value from memory */
u16 read_mem16(u16 addr); /* Read a 16-bit value from memory */
void zmem(u16 addr); /* Clear a memory address */
void write_mem(u16 addr, u8 val); /* Write an 8-bit value to memory */
void write_mem16(u16 addr, u16 val); /* Write a 16-bit value to memory */
void write_nmem(u16 addr, const u8 *val, u16 n); /* Write an array of bytes to contiguous memory */
void inc_mem(u16 addr); /* Increment the value stored at an address */
void dec_mem(u16 addr); /* Decrement the value stored at an address */
void add_mem(u16 addr, u8 val); /* Add a value to an address */
void subtr_mem(u16 addr, u8 val); /* Subtract a value from an address */
void and_mem(u16 addr, u8 val); /* Bitwise and with a value stored in memory */
void or_mem(u16 addr, u8 val); /* Bitwise or with a value stored in memory */
u8 *get_ptr(u16 addr); /* Get a pointer to a specific address */

#endif /* CCC_MEMORY_H */
