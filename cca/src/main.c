#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "opcodes.h"

int main(int argc, char **argv) {
    int asm_fd = 0, bin_fd = 0;
    char *asm_buff = NULL;
    char bin_buff[0x8000] = {};
    char *bin_p = bin_buff;
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

    return 0;
}