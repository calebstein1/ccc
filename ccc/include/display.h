#ifndef CCC_DISPLAY_H
#define CCC_DISPLAY_H

#define SCREEN_FPS 60
#define SCREEN_TICKS_PER_FRAME (1000 / SCREEN_FPS)

#define BG_R (prg_ram[0x2001])
#define BG_G (prg_ram[0x2002])
#define BG_B (prg_ram[0x2003])

typedef enum gpu_state {
    GPU_STP,
    GPU_RN,
} gpu_state;

extern gpu_state g_state;

void start_gpu();
void stop_gpu();

#endif //CCC_DISPLAY_H
