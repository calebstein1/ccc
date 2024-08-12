#include <stdio.h>
#include <fcntl.h>

#include "globals.h"
#include "prg.h"

int parse_prg(char *prg) {
    int fd;
    if ((fd = open(prg, O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }

    return 0;
}
