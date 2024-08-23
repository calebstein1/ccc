#include <stdio.h>
#include <SDL2/SDL.h>

#include "display.h"
#include "cpu.h"

gpu_state g_state = GPU_STP;

void start_gpu() {
    SDL_Window *disp;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Failed to init SDL: %s\n", SDL_GetError());
        return;
    }
    int x_res = 800, y_res = 600;
    char win_title[256];
    snprintf(win_title, 256, "CCC %s", CCC_VER);
    disp = SDL_CreateWindow(win_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x_res, y_res, SDL_WINDOW_SHOWN);
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

    while (g_state == GPU_RN) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                g_state = GPU_STP;
            }
        }

        SDL_SetRenderDrawColor(renderer, BG_R, BG_G, BG_B, 0xff);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(disp);
    SDL_Quit();
}

void stop_gpu() {
    g_state = GPU_STP;
}
