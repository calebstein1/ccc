#include <stdio.h>

/* Posix Headers */
#include <pthread.h>

#include "display.h"
#include "cpu.h"
#include "loader.h"
#include "colors.h"

int
main(int argc, char **argv) {
	pthread_t cpu_thread;

	(void)argc;

	/* Skip splash if loading a program directly */
	if (!argv[1] || load_prg(argv[1])) {
		printf("\t\t  %s***************************%s\n", CYANB, RESET);
		printf("\t\t  %s* %s  ____    ____    ____%s  *%s\n", CYANB, YELLOW, CYANB, RESET);
		printf("\t\t  %s* %s / ___|  / ___|  / ___|%s *%s\n", CYANB, YELLOW, CYANB, RESET);
		printf("\t\t  %s* %s| |     | |     | |%s     *%s\n", CYANB, YELLOW, CYANB, RESET);
		printf("\t\t  %s* %s| |___  | |___  | |___%s  *%s\n", CYANB, YELLOW, CYANB, RESET);
		printf("\t\t  %s* %s \\____|  \\____|  \\____|%s *%s\n", CYANB, YELLOW, CYANB, RESET);
		printf("\t\t  %s*                         *%s\n", CYANB, RESET);
		printf("\t\t  %s***************************%s\n\n", CYANB, RESET);
		printf("\t\tWelcome to %sCCC %s%s%s\n\n\tRun %shelp%s at the prompt to list available commands\n\n", YELLOWB, REDB, CCC_VER, RESET, GREENB, RESET);
	} else {
		c_state = PRG_RN;
	}

	/*
	 * The CPU process would block the display if they were run on the same
	 * thread, so we run the CPU process on a background thread since some
	 * platforms (MacOS) require the display thread to be the main thread.
	 * The two threads will communicate using the CPU's simulated RAM space.
	 */
	pthread_create(&cpu_thread, NULL, run_cpu, NULL);
	run_gpu();
	pthread_join(cpu_thread, NULL);

	return 0;
}
