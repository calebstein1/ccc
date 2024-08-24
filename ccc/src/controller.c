#include <SDL2/SDL.h>

#include "controller.h"
#include "cpu.h"

void get_controller_state(SDL_Event *e) {
    while(SDL_PollEvent(e)) {
        if (e->type == SDL_KEYDOWN) {
            if (e->key.keysym.sym == K_PRIMARY) {
                CONTROLLER_BITFIELD |= 0b00000001;
            }
            if (e->key.keysym.sym == K_SECONDARY) {
                CONTROLLER_BITFIELD |= 0b00000010;
            }
            if (e->key.keysym.sym == K_LEFT) {
                CONTROLLER_BITFIELD |= 0b00000100;
            }
            if (e->key.keysym.sym == K_RIGHT) {
                CONTROLLER_BITFIELD |= 0b00001000;
            }
            if (e->key.keysym.sym == K_UP) {
                CONTROLLER_BITFIELD |= 0b00010000;
            }
            if (e->key.keysym.sym == K_DOWN) {
                CONTROLLER_BITFIELD |= 0b00100000;
            }
        }
        if (e->type == SDL_KEYUP) {
            if (e->key.keysym.sym == K_PRIMARY) {
                CONTROLLER_BITFIELD &= 0b11111110;
            }
            if (e->key.keysym.sym == K_SECONDARY) {
                CONTROLLER_BITFIELD &= 0b11111101;
            }
            if (e->key.keysym.sym == K_LEFT) {
                CONTROLLER_BITFIELD &= 0b11111011;
            }
            if (e->key.keysym.sym == K_RIGHT) {
                CONTROLLER_BITFIELD &= 0b11110111;
            }
            if (e->key.keysym.sym == K_UP) {
                CONTROLLER_BITFIELD &= 0b11101111;
            }
            if (e->key.keysym.sym == K_DOWN) {
                CONTROLLER_BITFIELD &= 0b11011111;
            }
        }
        if (e->type == SDL_QUIT) {
            stop_cpu();
        }
    }
}