#include <stdio.h>
#include <SDL2/SDL.h>

#include "display.h"
#include "controller.h"
#include "cpu.h"

gpu_state g_state = GPU_STP;
u8 gpu_rom[0x8000];

void
run_gpu(void) {
	unsigned long int last_frame = SDL_GetTicks();
	unsigned long int cur_frame, d_frame;
	const int x_dims[] = { 128, 64, 256, 256 };
	const int y_dims[] = { 128, 64, 256, 224 };
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

	SCREEN_RESOLUTION_MODE = S128;
	PIXEL_SIZE = 4;

	init_window:
	sres_x = x_dims[SCREEN_RESOLUTION_MODE];
	sres_y = y_dims[SCREEN_RESOLUTION_MODE];
	win_size_x = sres_x * PIXEL_SIZE;
	win_size_y = sres_y * PIXEL_SIZE;
	snprintf(win_title, 256, "CCC %s", CCC_VER);
	disp = SDL_CreateWindow(win_title, win_pos_x, win_pos_y, win_size_x, win_size_y, SDL_WINDOW_SHOWN);
	if (!disp) {
		fprintf(stderr, "Failed to create window: %s\n", SDL_GetError());
		return;
	}
	renderer = SDL_CreateRenderer(disp, -1, SDL_RENDERER_SOFTWARE);
	if (!renderer) {
		fprintf(stderr, "Failed to create renderer: %s\n", SDL_GetError());
		return;
	}
	g_state = GPU_RN;

	while (g_state == GPU_RN && c_state) {
		get_controller_state(&e);

		cur_frame = SDL_GetTicks();
		d_frame = cur_frame - last_frame;
		if (d_frame < SCREEN_TICKS_PER_FRAME) {
			continue;
		}
		last_frame = cur_frame;
		FRM_CNT++;

		SDL_SetRenderDrawColor(renderer, BG_R, BG_G, BG_B, 0xff);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
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
