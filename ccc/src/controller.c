#include <SDL2/SDL.h>

#include "controller.h"
#include "cpu.h"

void get_controller_state(SDL_Event *e) {
    while(SDL_PollEvent(e)) {
        if (e->type == SDL_KEYDOWN) {
            if (e->key.keysym.sym == K_PRIMARY) {
                CONTROLLER_BITFIELD |= 1;
            }
            if (e->key.keysym.sym == K_SECONDARY) {
                CONTROLLER_BITFIELD |= 2;
            }
            if (e->key.keysym.sym == K_LEFT) {
                CONTROLLER_BITFIELD |= 4;
            }
            if (e->key.keysym.sym == K_RIGHT) {
                CONTROLLER_BITFIELD |= 8;
            }
            if (e->key.keysym.sym == K_UP) {
                CONTROLLER_BITFIELD |= 16;
            }
            if (e->key.keysym.sym == K_DOWN) {
                CONTROLLER_BITFIELD |= 32;
            }
        }
        if (e->type == SDL_KEYUP) {
            if (e->key.keysym.sym == K_PRIMARY) {
                CONTROLLER_BITFIELD &= 254;
            }
            if (e->key.keysym.sym == K_SECONDARY) {
                CONTROLLER_BITFIELD &= 253;
            }
            if (e->key.keysym.sym == K_LEFT) {
                CONTROLLER_BITFIELD &= 251;
            }
            if (e->key.keysym.sym == K_RIGHT) {
                CONTROLLER_BITFIELD &= 247;
            }
            if (e->key.keysym.sym == K_UP) {
                CONTROLLER_BITFIELD &= 239;
            }
            if (e->key.keysym.sym == K_DOWN) {
                CONTROLLER_BITFIELD &= 223;
            }
        }
    }
}