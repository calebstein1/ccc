#ifndef CCC_DISPLAY_H
#define CCC_DISPLAY_H

#include "fixed.h"

#define SCREEN_FPS 60
#define SCREEN_TICKS_PER_FRAME (1000 / SCREEN_FPS)

#define MAX_SPRITES 8
#define SPR_NUM_PIXELS 64

#define FRM_CNT (prg_ram[0x2000])

#define SPR_PAL (prg_ram[0x2100])
#define BG_R (prg_ram[0x2002])
#define BG_G (prg_ram[0x2003])
#define BG_B (prg_ram[0x2004])
#define SCREEN_RESOLUTION_MODE (prg_ram[0x2005])
#define PIXEL_SIZE (prg_ram[0x2006])

#define HW_PALETTE		\
	X(0x00, 0x00, 0x00)	\
	X(0x00, 0xff, 0x00)	\
	X(0xff, 0x00, 0x00)	\
	X(0xff, 0xff, 0xff)

typedef enum gpu_state {
	GPU_STP,
	GPU_RN,
	GPU_RST
} gpu_state;

typedef enum resolution_mode {
    S128,
    S64,
    S256,
    NIN
} resolution_mode;

struct sprite_slot_t {
    u8 in_use;
    u8 spr_num;
    u8 spr_bnk;
    u8 spr_x;
    u8 spr_y;
    u8 spr_subp;
    u8 spr_pal;
    u8 spr_prop;
};

struct color_t {
	u8 r;
	u8 g;
	u8 b;
};

extern gpu_state g_state;
extern u8 gpu_rom[0x8000];

void run_gpu(void);
void restart_gpu(void);

#endif /* CCC_DISPLAY_H */
