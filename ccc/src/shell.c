#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "loader.h"
#include "opcodes.h"
#include "console.h"
#include "shell.h"
#include "cpu.h"

void help_f(const uint8_t *args, char *arg) {
    puts("  peek [addr] - print the byte stored at [addr]");
    puts("  poke [addr] [val] - write the byte [val] to [addr]");
    puts("  load [prg] - attempt to load program located at path [prg] into memory");
    puts("  run - run the program loaded by 'load'");
    puts("  status - display the status of CPU registers, pc, s, and p");
    puts("  continue - continue execution of a running program from a breakpoint");
    puts("  exit - shutdown CCC");

    if (arg) {
        free(arg);
    }
}

void peek_f(const uint8_t *args, char *arg) {
    printf("%d\n", (uint16_t)*(prg_ram + args[0] + (args[1] * 0x100)));

    if (arg) {
        free(arg);
    }
}

void poke_f(const uint8_t *args, char *arg) {
    uint8_t *addr = prg_ram + args[0] + (args[1] * 0x100);
    *addr = args[2];

    if (arg) {
        free(arg);
    }
}

void load_f(const uint8_t *args, char *arg) {
    memset(&prg_ram[0x8000], 0, 0x8000);
    if (load_prg(arg)) {
        fprintf(stderr, "Failed to load program: %s\n", arg);
    } else {
        printf("Loaded program: %s\n", arg);
        state = PRG_LD;
    }

    if (arg) {
        free(arg);
    }
}

void run_f(const uint8_t *args, char *arg) {
    if (state == BOOT) {
        fputs("No program loaded\n", stderr);
    } else if (state == PRG_DBG) {
        fputs("Program already running\n", stderr);
    } else {
        state = PRG_RN;
    }

    if (arg) {
        free(arg);
    }
}

void status_f(const uint8_t *args, char *arg) {
    printf("Next: %s\n", str_tbl[t6502[*pc]]);
    print_registers();

    if (arg) {
        free(arg);
    }
}

void continue_f(const uint8_t *args, char *arg) {
    if (state != PRG_DBG) {
        fputs("Not at a breakpoint\n", stderr);
    } else {
        prg_ram[0x4000] = 0;
        state = PRG_RN;
    }

    if (arg) {
        free(arg);
    }
}

void exit_f(const uint8_t *args, char *arg) {
    stop_cpu();

    if (arg) {
        free(arg);
    }
}

void shell_prompt() {
    static void (*shell_func[])(const uint8_t *args, char *arg) = {
#define X(op, fn, ...) fn,
            SHELL_CMD_TBL
#undef X
    };

    static char *shell_str[] = {
#define X(op, fn, str, ...) str,
            SHELL_CMD_TBL
#undef X
    };

    char cmd_buff[CMD_BUFF_SIZE];
    char *cmd_parse;
    shell_cmd cmd;
    uint16_t arg_buff;
    uint8_t args[MAX_CMD_ARGS] = {};
    char *arg = NULL;
    uint8_t i = 0;

    fgets(cmd_buff, CMD_BUFF_SIZE, stdin);
    if (*cmd_buff == '\n') return;

    cmd_parse = strtok(cmd_buff, " \n");
    while (i < SHELL_CMD_COUNT && strcmp(cmd_parse, shell_str[i]) != 0) {
        i++;
    }
    if (i == SHELL_CMD_COUNT) {
        fprintf(stderr, "Invalid command: %s\n", cmd_parse);
        return;
    }
    cmd = i;
    i = 0;
    while ((cmd_parse = strtok(NULL, " \n"))) {
        if ('0' <= *cmd_parse && *cmd_parse <= '9') {
            arg_buff = (uint16_t)strtol(cmd_parse, 0, 0);
            if (arg_buff < 0xff) {
                args[i++] = arg_buff;
                i++;
            } else {
                args[i++] = arg_buff & 0xff;
                args[i++] = arg_buff >> 8;
            }
            if (i == MAX_CMD_ARGS) break;
        } else {
            arg = malloc(CMD_BUFF_SIZE);
            strcpy(arg, cmd_parse);
        }
    }

    (*shell_func[cmd])(args, arg);
}
