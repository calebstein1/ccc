#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "globals.h"
#include "opcodes.h"

#define MASK 0xff

int main(int argc, char **argv) {
    int asm_fd = 0, bin_fd = 0;
    size_t c = 0;
    char asm_buff[0xffff] = {};
    char *cur_tok = NULL;
    uint8_t bin_buff[0x8000] = {};
    uint8_t *bin_p = bin_buff;
    uint8_t low, hi;
    uint64_t word;
    char *str_tbl[] = {
#define X(opcode, op_fn, str_lit, ...) str_lit,
            OPCODES_LIST
#undef X
    };
    struct stat asm_stat = {};

    if (argc != 2) {
        fputs("Please supply exactly one ccasm file\n", stderr);
        return -1;
    }
    if (strcmp(&argv[1][strlen(argv[1]) - 6], ".ccasm") != 0) {
        fputs("Please make sure your file has the .ccasm file extension\n", stderr);
        return -1;
    }
    if ((asm_fd = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }
    argv[1][strlen(argv[1]) - 6] = '\0';
    fstat(asm_fd, &asm_stat);
    lseek(asm_fd, 0, SEEK_SET);
    read(asm_fd, asm_buff, asm_stat.st_size);
    close(asm_fd);

    cur_tok = strtok(asm_buff, " \n\t");
    goto loop;
    while ((cur_tok = strtok(NULL, " \n\t"))) {
        loop:
        if (*cur_tok == '#') {
            *bin_p++ = (uint8_t)strtol(cur_tok + 1, NULL, 10);
            *bin_p++ = NOP;
            c += 2;
        } else if (*cur_tok == '$') {
            word = strtol(cur_tok + 1, NULL, 16);
            hi = (uint8_t)(word >> 8);
            low = (uint8_t)(word & MASK);
            *bin_p++ = low;
            *bin_p++ = hi;
            *bin_p++ = NOP;
            c += 3;
        } else {
            int i = 0;
            for (; i < OPCODE_COUNT; i++) {
                if (strcmp(cur_tok, str_tbl[i]) == 0) break;
            }
            *bin_p++ = (uint8_t)i;
            c++;
        }
    }

    bin_fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    write(bin_fd, bin_buff, c);
    close(bin_fd);

    return 0;
}
