#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "globals.h"
#include "loader.h"

int load_os() {
    struct stat os_stat = {};
    int fd;
    if ((fd = open("ccos.bin", O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }
    fstat(fd, &os_stat);
    if (os_stat.st_size > 0xff) {
        fputs("OS too large\n", stderr);
        return -1;
    }
    lseek(fd, 0, SEEK_SET);
    read(fd, pc, os_stat.st_size);
    close(fd);

    return 0;
}

int load_prg(char *prg) {
    struct stat p_stat = {};
    int fd;
    if ((fd = open(prg, O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }
    fstat(fd, &p_stat);
    if (p_stat.st_size > 0x7f00) {
        fputs("Program too large\n", stderr);
        return -1;
    }
    lseek(fd, 0, SEEK_SET);
    read(fd, &prg_ram[0x8000], p_stat.st_size);
    close(fd);

    return 0;
}
