#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "globals.h"
#include "shell.h"
#include "cpu.h"

void help_f(const uint8_t *args) {
    puts("  peek [addr] - print the byte stored at [addr]");
    puts("  poke [addr] [val] - write the byte [val] to [addr]");
}

void peek_f(const uint8_t *args) {
    printf("%d\n", (uint16_t)*(prg_ram + args[0] + (args[1] * 0x100)));
}

void poke_f(const uint8_t *args) {
    uint8_t *addr = prg_ram + args[0] + (args[1] * 0x100);
    *addr = args[2];
}

void load_f(const uint8_t *args) {

}

void run_f(const uint8_t *args) {

}

void exit_f(const uint8_t *args) {
    stop_cpu();
}

void shell_prompt() {
    static void (*shell_func[SHELL_CMD_COUNT])(const uint8_t *args) = {
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
        arg_buff = (uint16_t)strtol(cmd_parse, 0, 0);
        if (arg_buff < 0xff) {
            args[i++] = arg_buff;
            i++;
        } else {
            args[i++] = arg_buff & 0xff;
            args[i++] = arg_buff >> 8;
        }
        if (i == MAX_CMD_ARGS) break;
    }

    (*shell_func[cmd])(args);
}
