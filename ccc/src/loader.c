#include <stdio.h>
#include <fcntl.h>

/* Posix Headers */
#include <unistd.h>
#include <sys/stat.h>

#include "display.h"
#include "cpu.h"
#include "loader.h"

int
load_prg(const char *prg) {
	struct stat p_stat;
	int fd;
	if ((fd = open(prg, O_RDONLY)) == -1) {
		return -1;
	}
	fstat(fd, &p_stat);
	if (p_stat.st_size > 0x10000) {
		fputs("Program too large\n", stderr);
		return -1;
	}
	lseek(fd, 0, SEEK_SET);
	read(fd, pc, 0x8000);
	read(fd, gpu_rom, 0x4000);
	read(fd, &prg_ram[0x2100], 0xff);
	close(fd);
	c_state = PRG_LD;

	return 0;
}
