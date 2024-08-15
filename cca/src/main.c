#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "globals.h"
#include "opcodes.h"

#define MASK 0xff
#define MAX_LABELS 256

int main(int argc, char **argv) {
    if (argc < 2) {
        fputs("Please supply exactly one asm file\n", stderr);
        return -1;
    }

    int asm_fd = 0, bin_fd = 0;
    bool os_mode = (argv[2] && strcmp(argv[2], "-os") == 0);
    size_t c = 0;
    uint16_t addr = os_mode ? 0xff00 : 0x8000;
    char asm_buff[0xffff] = {};
    char *cur_tok = NULL;
    uint8_t bin_buff[0x7f00] = {};
    uint8_t *bin_p = bin_buff;
    uint8_t low, hi;
    uint64_t word;
    char *lbl_tbl[MAX_LABELS] = {};
    uint16_t addr_tbl[MAX_LABELS] = {};
    uint8_t lbl_count = 0;
    struct stat asm_stat = {};

    if (strcmp(&argv[1][strlen(argv[1]) - 4], ".asm") != 0) {
        fputs("Please make sure your file has the .asm file extension\n", stderr);
        return -1;
    }
    if ((asm_fd = open(argv[1], O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }
    strcpy(&argv[1][strlen(argv[1]) - 3], "bin");
    fstat(asm_fd, &asm_stat);
    lseek(asm_fd, 0, SEEK_SET);
    read(asm_fd, asm_buff, asm_stat.st_size);
    close(asm_fd);

    // First pass replaces labels with addresses
    cur_tok = strtok(asm_buff, " \n\t");
    do {
        if (cur_tok[strlen(cur_tok) - 1] == ':') {
            cur_tok[strlen(cur_tok) - 1] = '\0';
            int i = 0;
            for (; i < MAX_LABELS; i++) {
                if (!lbl_tbl[i] || strcmp(cur_tok, lbl_tbl[i]) == 0) break;
            }
            if (!lbl_tbl[i]) {
                lbl_tbl[i] = malloc(strlen(cur_tok) + 1);
                strcpy(lbl_tbl[i], cur_tok);
                lbl_count++;
            }
            addr_tbl[i] = addr;
            for (i = 0; i < strlen(cur_tok); i++) {
                cur_tok[i] = '\n';
            }
        } else if (*cur_tok == '#') {
            addr += 2;
        } else if (*cur_tok == '$') {
            addr += 3;
        } else {
            int i = 0;
            for (; i < OPCODE_COUNT; i++) {
                if (strcmp(cur_tok, str_tbl[i]) == 0) break;
            }
            if (i < OPCODE_COUNT) {
                addr += 1;
            } else {
                addr += 3;
            }
        }
        cur_tok[strlen(cur_tok)] = '\n';
        cur_tok[strlen(cur_tok)] = '\n';
    } while ((cur_tok = strtok(NULL, " \n\t")));

    // Second pass generates machine code
    cur_tok = strtok(asm_buff, " \n\t");
    do {
        if (*cur_tok == '#') {
            int b = *(cur_tok + 1) == '$' ? 16 : 10;
            *bin_p++ = (uint8_t) strtol(b == 16 ? cur_tok + 2 : cur_tok + 1, NULL, b);
            *bin_p++ = NOP;
            c += 2;
        } else if (*cur_tok == '$') {
            word = strtol(cur_tok + 1, NULL, 16);
            hi = (uint8_t) (word >> 8);
            low = (uint8_t) (word & MASK);
            *bin_p++ = low;
            *bin_p++ = hi;
            *bin_p++ = NOP;
            c += 3;
        } else {
            int i = 0;
            for (; i < OPCODE_COUNT; i++) {
                if (strcmp(cur_tok, str_tbl[i]) == 0) break;
            }
            if (i < OPCODE_COUNT) {
                *bin_p++ = (uint8_t) i;
                c++;
            } else {
                i = 0;
                for (; i < MAX_LABELS; i++) {
                    if (!lbl_tbl[i] || strcmp(cur_tok, lbl_tbl[i]) == 0) break;
                }
                word = addr_tbl[i];
                hi = (uint8_t) (word >> 8);
                low = (uint8_t) (word & MASK);
                *bin_p++ = low;
                *bin_p++ = hi;
                *bin_p++ = NOP;
                c += 3;
            }
        }
    } while ((cur_tok = strtok(NULL, " \n\t")));

    bin_fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    write(bin_fd, bin_buff, c);
    close(bin_fd);
    if (os_mode) {
        bin_fd = open("address.txt", O_RDWR | O_CREAT, 0644);
        for (int i = 0; i < lbl_count; i++) {
            lseek(bin_fd, 0, SEEK_END);
            dprintf(bin_fd, "%s\t%x\n", lbl_tbl[i], addr_tbl[i]);
        }
        close(bin_fd);
    }
    for (int i = 0; i < MAX_LABELS; i++) {
        if (!lbl_tbl[i]) break;
        free(lbl_tbl[i]);
    }

    return 0;
}
