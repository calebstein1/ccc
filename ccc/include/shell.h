#ifndef CCC_SHELL_H
#define CCC_SHELL_H

#define CMD_BUFF_SIZE 256
#define MAX_CMD_ARGS 4

#define SHELL_CMD_TBL                      \
    X(HELP, help_f, "help")                \
    X(PEEK, peek_f, "peek")                \
    X(POKE, poke_f, "poke")                \
    X(LS, ls_f, "ls")                      \
    X(CD, cd_f, "cd")                      \
    X(LOAD, load_f, "load")                \
    X(RUN, run_f, "run")                   \
    X(RUNANYWAY, runanyway_f, "runanyway") \
    X(STATUS, status_f, "status")          \
    X(CONTINUE, continue_f, "continue")    \
    X(CLEAR, clear_f, "clear")             \
    X(EXIT, exit_f, "exit")

typedef enum shell_cmd {
#define X(op, fn, str) op,
    SHELL_CMD_TBL
#undef X
    SHELL_CMD_COUNT
} shell_cmd;

/* Function prototypes */
void shell_prompt(void);
#define X(op, fn, str) void fn(const u8 *args, const char *arg);
SHELL_CMD_TBL
#undef X

#endif
