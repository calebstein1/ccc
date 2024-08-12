#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#include "globals.h"
#include "prg.h"

int parse_prg(char *prg) {
    struct stat p_stat = {};
    int fd;
    if ((fd = open(prg, O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }
    fstat(fd, &p_stat);
    if (p_stat.st_size > 0x8000) {
        fprintf(stderr, "Program too large\n");
        return -1;
    }
    lseek(fd, 0, SEEK_SET);
    read(fd, pc, p_stat.st_size);
    close(fd);

    return 0;
}
