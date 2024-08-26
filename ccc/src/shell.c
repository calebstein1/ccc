#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#include "fixed.h"
#include "loader.h"
#include "shell.h"
#include "cpu.h"
#include "colors.h"

/* Function prototypes */
#define X(op, fn, str) void fn(const u8 *args, const char *arg);
        SHELL_CMD_TBL
#undef X

void
shell_prompt(void) {
    static void (*shell_func[])(const u8 *args, const char *arg) = {
#define X(op, fn, str) fn,
            SHELL_CMD_TBL
#undef X
    };

    static const char *shell_str[] = {
#define X(op, fn, str) str,
            SHELL_CMD_TBL
#undef X
    };

    char cmd_buff[CMD_BUFF_SIZE];
    char *cmd_parse;
    shell_cmd cmd;
    u16 arg_buff;
    u8 args[MAX_CMD_ARGS];
    char *arg = NULL;
    u8 i = 0;

    char dir_buff[CMD_BUFF_SIZE];
    getcwd(dir_buff, CMD_BUFF_SIZE);

    printf("%s[%s%s%s@%sCCC %s %s%s%s]%s$ ", REDB, CYANB, getlogin(), GREENB, BLUEB, CCC_VER, PURPLEB, dir_buff, REDB, RESET);
    fgets(cmd_buff, CMD_BUFF_SIZE, stdin);
    if (*cmd_buff == '\n') return;

    if (!(cmd_parse = strtok(cmd_buff, " \n"))) {
        return;
    }
    while (i < SHELL_CMD_COUNT && strcmp(cmd_parse, shell_str[i]) != 0) {
        i++;
    }
    if (i == SHELL_CMD_COUNT) {
        fprintf(stderr, "Invalid command: %s%s%s\n", REDB, cmd_parse, RESET);
        return;
    }
    cmd = i;
    i = 0;
    while ((cmd_parse = strtok(NULL, " \n"))) {
        if ('0' <= *cmd_parse && *cmd_parse <= '9') {
            arg_buff = (u16)strtol(cmd_parse, 0, 0);
            if (arg_buff < 0xff) {
                args[i++] = arg_buff;
                i++;
            } else {
                args[i++] = arg_buff & 0xff;
                args[i++] = arg_buff >> 8;
            }
            if (i == MAX_CMD_ARGS) break;
        } else {
            if (!(arg = malloc(CMD_BUFF_SIZE))) {
                perror("malloc");
                return;
            }
            strcpy(arg, cmd_parse);
        }
    }

    (*shell_func[cmd])(args, arg);
    if (arg) {
        free(arg);
    }
}

/*
 * Shell interpreter functions
 */
void
help_f(const u8 *args, const char *arg) {
    printf("  %speek %s[addr] %s- print the byte stored at %s[addr]%s\n", GREENB, CYAN, RESET, CYAN, RESET);
    printf("  %spoke %s[addr] %s[val] %s- write the byte %s[val]%s to %s[addr]%s\n", GREENB, CYAN, BLUE, RESET, BLUE, RESET, CYAN, RESET);
    printf("  %sload %s[prg] %s- attempt to load program located at path %s[prg]%s into memory\n", GREENB, CYAN, RESET, CYAN, RESET);
    printf("  %sls %s[dir] %s- list the contents of the current directory or the directory %s[dir]%s\n", GREENB, CYAN, RESET, CYAN, RESET);
    printf("  %scd %s[dir] %s- change the current working directory to %s[dir]%s\n", GREENB, CYAN, RESET, CYAN, RESET);
    printf("  %srun %s- run the program loaded by %sload%s\n", GREENB, RESET, GREENB, RESET);
    printf("  %sstatus %s- display the status of CPU registers, pc, s, and p\n", GREENB, RESET);
    printf("  %scontinue %s- continue execution of a running program from a breakpoint\n", GREENB, RESET);
    printf("  %sclear %s- clears the terminal screen\n", GREENB, RESET);
    printf("  %sexit %s- shutdown CCC\n", GREENB, RESET);
    (void)args;
    (void)arg;
}

void
peek_f(const u8 *args, const char *arg) {
    printf("%d\n", (u16)*(prg_ram + args[0] + (args[1] * 0x100)));
    (void)arg;
}

void
poke_f(const u8 *args, const char *arg) {
    u8 *addr = prg_ram + args[0] + (args[1] * 0x100);
    *addr = args[2];
    (void)arg;
}

void
ls_f(const u8 *args, const char *arg) {
    const char *filetypes[] = { "???", "FIFO", "CHR", "",
                          "DIR", "", "BLK", "",
                          "FILE", "", "SYM", "",
                          "SOCK", "", "WHT", "" };
    const char *fcolors[] = { RESET, RESET, RESET, RESET,
                                BLUE, RESET, YELLOW, RESET,
                                RESET, RESET, PURPLE, RESET,
                                RED, RESET, RESET, RESET };
    DIR *dir;
    struct dirent *dir_itm;
    if (!(dir = opendir(arg ? arg : "."))) {
        perror("opendir");
        return;
    }
    rewinddir(dir);
    while ((dir_itm = readdir(dir))) {
        printf("%s%-16s%s\t%s\n", fcolors[dir_itm->d_type], dir_itm->d_name, RESET, filetypes[dir_itm->d_type]);
    }
    (void)args;
}

void cd_f(const u8 *args, const char *arg) {
    if (chdir(arg ? arg : ".")) {
        perror("chdir");
    }
    (void)args;
}

void
load_f(const u8 *args, const char *arg) {
    memset(&prg_ram[0x8000], 0, 0x8000);
    if (load_prg(arg)) {
        fprintf(stderr, "Failed to load program: %s%s%s\n", REDB, arg, RESET);
    } else {
        printf("Loaded program: %s%s%s\n", GREENB, arg, RESET);
        c_state = PRG_LD;
    }
    (void)args;
}

void
run_f(const u8 *args, const char *arg) {
    init_ccrom();
    if (c_state == BOOT) {
        fputs("No program loaded\n", stderr);
    } else if (c_state == PRG_DBG) {
        fputs("Program already running\n", stderr);
    } else {
        c_state = PRG_RN;
    }
    (void)args;
    (void)arg;
}

void
runanyway_f(const u8 *args, const char *arg) {
    init_ccrom();
    if (c_state == PRG_DBG) {
        fputs("Program already running\n", stderr);
    } else {
        c_state = PRG_RN;
    }
    (void)args;
    (void)arg;
}

void
status_f(const u8 *args, const char *arg) {
    printf("a: %d\nx: %d\ny: %d\npc: 0x%x\ns: 0x%x\np: %d%d%d%d%d%d\n   NVDIZC\n",
           a, x, y, (u16)(pc - prg_ram), s, GET_N, GET_V, GET_D, GET_I, GET_Z, GET_C);
    (void)args;
    (void)arg;
}

void
continue_f(const u8 *args, const char *arg) {
    if (c_state != PRG_DBG) {
        fputs("Not at a breakpoint\n", stderr);
    } else {
        prg_ram[0x4000] = 0;
        c_state = PRG_RN;
    }
    (void)args;
    (void)arg;
}

void
clear_f(const u8 *args, const char *arg) {
    (void)args;
    (void)arg;
}

void
exit_f(const u8 *args, const char *arg) {
    stop_cpu();
    (void)args;
    (void)arg;
}
