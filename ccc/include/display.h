#ifndef CCC_DISPLAY_H
#define CCC_DISPLAY_H

#include <stdint.h>

#define SCREEN_FPS 60
#define SCREEN_TICKS_PER_FRAME (1000 / SCREEN_FPS)

#define FRM_CNT (prg_ram[0x2000])

#define BG_R (prg_ram[0x2002])
#define BG_G (prg_ram[0x2003])
#define BG_B (prg_ram[0x2004])
#define SCREEN_RESOLUTION_MODE (prg_ram[0x2005])
#define PIXEL_SIZE (prg_ram[0x2006])

#define HW_PALETTE                         \
    X(0x00, 0x00, 0x00, ...) \
    X(0xff, 0xff, 0xff, ...)

typedef enum gpu_state {
    GPU_STP,
    GPU_RN,
    GPU_RST,
} gpu_state;

struct color_t {
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

extern gpu_state g_state;
extern uint8_t gpu_rom[0x8000];
extern int screen_resolution;

void start_gpu(void);
void restart_gpu(void);

#endif //CCC_DISPLAY_H
