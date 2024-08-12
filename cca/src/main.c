#include <stdio.h>
#include <stdlib.h>
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
    char *asm_buff = NULL;
    char *cur_tok = NULL;
    unsigned char bin_buff[0x8000] = {};
    unsigned char *bin_p = bin_buff;
    unsigned char low, hi;
    unsigned long word;
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
    if (!(asm_buff = malloc(asm_stat.st_size))) {
        perror("malloc");
        return -1;
    }
    lseek(asm_fd, 0, SEEK_SET);
    read(asm_fd, asm_buff, asm_stat.st_size);
    close(asm_fd);

    cur_tok = strtok(asm_buff, " \n\t");
    goto loop;
    while ((cur_tok = strtok(NULL, " \n\t"))) {
        loop:
        if (*cur_tok == '#') {
            *bin_p++ = (unsigned char)strtol(cur_tok + 1, NULL, 10);
            *bin_p++ = NOP;
            c += 2;
        } else if (*cur_tok == '$') {
            word = strtol(cur_tok + 1, NULL, 16);
            hi = (unsigned char)(word >> 8);
            low = (unsigned char)(word & MASK);
            *bin_p++ = low;
            *bin_p++ = hi;
            *bin_p++ = NOP;
            c += 3;
        } else {
            int i = 0;
            for (; i < OPCODE_COUNT; i++) {
                if (strcmp(cur_tok, str_tbl[i]) == 0) break;
            }
            *bin_p++ = (unsigned char)i;
            c++;
        }
    }
    free(asm_buff);

    bin_fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    write(bin_fd, bin_buff, c);
    close(bin_fd);

    return 0;
}
