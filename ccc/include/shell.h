#ifndef CCC_SHELL_H
#define CCC_SHELL_H

#define CMD_BUFF_SIZE 256
#define MAX_CMD_ARGS 4
#define SHELL_CMD_COUNT 8

#define SHELL_CMD_TBL                    \
    X(HELP, help_f, "help")              \
    X(PEEK, peek_f, "peek")              \
    X(POKE, poke_f, "poke")              \
    X(LOAD, load_f, "load")              \
    X(RUN, run_f, "run")                 \
    X(STATUS, status_f, "status")        \
    X(CONTINUE, continue_f, "continue")  \
    X(EXIT, exit_f, "exit")

typedef enum shell_cmd {
#define X(op, ...) op,
    SHELL_CMD_TBL
#undef X
} shell_cmd;

void shell_prompt();

#endif //CCC_SHELL_H
