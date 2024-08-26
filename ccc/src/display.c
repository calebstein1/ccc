#include <stdio.h>
#include <SDL2/SDL.h>

#include "display.h"
#include "controller.h"
#include "cpu.h"

gpu_state g_state = GPU_STP;
uint8_t gpu_rom[0x8000];
int screen_resolution;

void start_gpu(void) {
    uint64_t last_frame = SDL_GetTicks64();
    uint64_t cur_frame, d_frame;
    const int screen_resolutions[] = { 128, 64, 256 };

    SDL_Window *disp;
    SDL_Renderer *renderer;
    SDL_Event e;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Failed to init SDL: %s\n", SDL_GetError());
        return;
    }
    int win_size;
    int win_x = SDL_WINDOWPOS_UNDEFINED, win_y = SDL_WINDOWPOS_UNDEFINED;
    char win_title[256];

    SCREEN_RESOLUTION_MODE = 0;
    PIXEL_SIZE = 6;

    init_window:
    screen_resolution = screen_resolutions[SCREEN_RESOLUTION_MODE];
    win_size = screen_resolution * PIXEL_SIZE;
    snprintf(win_title, 256, "CCC %s", CCC_VER);
    disp = SDL_CreateWindow(win_title, win_x, win_y, win_size, win_size, SDL_WINDOW_SHOWN);
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

        cur_frame = SDL_GetTicks64();
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

    SDL_GetWindowPosition(disp, &win_x, &win_y);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(disp);
    if (g_state == GPU_RST) {
        goto init_window;
    }
    SDL_Quit();
}

void restart_gpu(void) {
    g_state = GPU_RST;
}
