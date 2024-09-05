#include <stdio.h>
#include <SDL2/SDL.h>

#include "display.h"
#include "controller.h"
#include "memory.h"
#include "cpu.h"

/* Prototypes for private functions */
void draw_all_sprites(SDL_Renderer *renderer, const struct color_t *pal);
void draw_sprite(const struct sprite_slot_t *spr, SDL_Renderer *renderer, const struct color_t *pal);
u8 get_cur_pixel(const struct sprite_slot_t *spr, const u8 *s_addr_low, const u8 *s_addr_hi, u8 i);

gpu_state g_state = GPU_STP;
u8 gpu_rom[0x8000];

void
run_gpu(void) {
	unsigned long int frame_start, frame_end, frame_time;
	const int x_dims[] = { 128, 64, 256, 256, 160 };
	const int y_dims[] = { 128, 64, 256, 224, 144 };
	int sres_x;
	int sres_y;
#define X(red, green, blue) { .r = red, .g = green, .b = blue },
	const struct color_t pal[] = {
			HW_PALETTE
	};
#undef X

	SDL_Window *disp;
	SDL_Renderer *renderer;
	SDL_Event e;

	int win_size_x;
	int win_size_y;
	int win_pos_x = SDL_WINDOWPOS_UNDEFINED, win_pos_y = SDL_WINDOWPOS_UNDEFINED;
	char win_title[256];

	(void)pal; /* delete once pal finalized */

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Failed to init SDL: %s\n", SDL_GetError());
		return;
	}

	write_mem(SCREEN_RESOLUTION_MODE, S128);
	write_mem(PIXEL_SIZE, 6);

	init_window:
	sres_x = x_dims[read_mem(SCREEN_RESOLUTION_MODE)];
	sres_y = y_dims[read_mem(SCREEN_RESOLUTION_MODE)];
	win_size_x = sres_x * read_mem(PIXEL_SIZE);
	win_size_y = sres_y * read_mem(PIXEL_SIZE);
	snprintf(win_title, 256, "CCC %s", CCC_VER);
	disp = SDL_CreateWindow(win_title, win_pos_x, win_pos_y, win_size_x, win_size_y, SDL_WINDOW_SHOWN);
	if (!disp) {
		fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
		return;
	}
	renderer = SDL_CreateRenderer(disp, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
		return;
	}
	g_state = GPU_RN;

	while (g_state == GPU_RN && c_state) {
		frame_start = SDL_GetTicks();
		inc_mem(FRM_CNT);

		get_controller_state(&e);

		SDL_SetRenderDrawColor(renderer, read_mem(BG_R), read_mem(BG_G), read_mem(BG_B), 0xff);
		SDL_RenderClear(renderer);

		draw_all_sprites(renderer, pal);

		SDL_RenderPresent(renderer);

		frame_end = SDL_GetTicks();
		if ((frame_time = frame_end - frame_start) < SCREEN_TICKS_PER_FRAME) {
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frame_time);
		}
	}

	SDL_GetWindowPosition(disp, &win_pos_x, &win_pos_y);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(disp);
	if (g_state == GPU_RST) {
		goto init_window;
	}
	SDL_Quit();
}

void
restart_gpu(void) {
	g_state = GPU_RST;
}

/*
 * Private GPU functions
 */

void
draw_all_sprites(SDL_Renderer *renderer, const struct color_t *pal) {
	u8 i;
	struct sprite_slot_t *cur_spr;

	for (i = 0; i < MAX_SPRITES; i++) {
		cur_spr = (struct sprite_slot_t *)(get_ptr(0x2200 + (i * sizeof(struct sprite_slot_t))));
		if (!cur_spr->spr_num && !cur_spr->spr_bnk) continue;

		draw_sprite(cur_spr, renderer, pal);
	}
}

void
draw_sprite(const struct sprite_slot_t *spr, SDL_Renderer *renderer, const struct color_t *pal) {
	u8 p_size = read_mem(PIXEL_SIZE);
	u8 i;
	u8 low = spr->spr_num << 4;
	u8 hi = spr->spr_bnk;
	u8 *s_addr = gpu_rom + MAKE_WORD;
	u8 c, cur_pxl;
	u16 spr_x = spr->spr_x * p_size;
	u16 spr_y = spr->spr_y * p_size;
	u8 spr_subp_x = spr->spr_subp_x >> 4;
	u8 spr_subp_y = spr->spr_subp_y >> 4;
	/* initialize y to 255 since we increment y each 8 pixels, and 0 is a multiple of 8 */
	u8 x_off = 0, y_off = 255;
	SDL_Rect pxl;

	pxl.h = p_size;
	pxl.w = p_size;

	for (i = 0; i < SPR_NUM_PIXELS; i++) {
		if ((i & 7) == 0) {
			x_off = 7;
			y_off++;
		} else {
			x_off--;
		}

		cur_pxl = get_cur_pixel(spr, s_addr + (i >> 3), s_addr + 8 + (i >> 3), i & 7);
		if (!cur_pxl) continue;

		c = read_mem(SPR_PAL + (spr->spr_pal * PAL_SIZE) + cur_pxl);
		SDL_SetRenderDrawColor(renderer, pal[c].r, pal[c].g, pal[c].b, 0xff);

		pxl.x = spr_x + (x_off * p_size) + ((spr_subp_x * p_size) >> SUBPIXEL_STEPS);
		pxl.y = spr_y + (y_off * p_size) + ((spr_subp_y * p_size) >> SUBPIXEL_STEPS);

		SDL_RenderFillRect(renderer, &pxl);
	}
}

u8
get_cur_pixel(const struct sprite_slot_t *spr, const u8 *s_addr_low, const u8 *s_addr_hi, u8 i) {
	u8 low = (*s_addr_low >> i) & 1;
	u8 hi = (*s_addr_hi >> i) & 1;
	switch (MAKE_WORD) {
		case 0x0:
			return 0;
		case 0x01:
			return 1;
		case 0x100:
			return 2;
		case 0x101:
			return 3;
		default:
			fprintf(stderr, "Processing sprite %u from bank %u resulted in an impossible pixel color on pixel %u, got %x\n\n",
				spr->spr_num, spr->spr_bnk, i, MAKE_WORD);
			stop_cpu();
	}

	return 0;
}
