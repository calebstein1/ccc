#include <SDL2/SDL.h>

#include "controller.h"
#include "bitfield.h"
#include "memory.h"
#include "cpu.h"

void
get_controller_state(SDL_Event *e) {
	while(SDL_PollEvent(e)) {
		if (e->type == SDL_KEYDOWN) {
			if (e->key.keysym.sym == K_PRIMARY) {
				or_mem(CONTROLLER_BITFIELD, S0);
			}
			if (e->key.keysym.sym == K_SECONDARY) {
				or_mem(CONTROLLER_BITFIELD, S1);
			}
			if (e->key.keysym.sym == K_LEFT) {
				or_mem(CONTROLLER_BITFIELD, S2);
			}
			if (e->key.keysym.sym == K_RIGHT) {
				or_mem(CONTROLLER_BITFIELD, S3);
			}
			if (e->key.keysym.sym == K_UP) {
				or_mem(CONTROLLER_BITFIELD, S4);
			}
			if (e->key.keysym.sym == K_DOWN) {
				or_mem(CONTROLLER_BITFIELD, S5);
			}
		}
		if (e->type == SDL_KEYUP) {
			if (e->key.keysym.sym == K_PRIMARY) {
				and_mem(CONTROLLER_BITFIELD, U0);
			}
			if (e->key.keysym.sym == K_SECONDARY) {
				and_mem(CONTROLLER_BITFIELD, U1);
			}
			if (e->key.keysym.sym == K_LEFT) {
				and_mem(CONTROLLER_BITFIELD, U2);
			}
			if (e->key.keysym.sym == K_RIGHT) {
				and_mem(CONTROLLER_BITFIELD, U3);
			}
			if (e->key.keysym.sym == K_UP) {
				and_mem(CONTROLLER_BITFIELD, U4);
			}
			if (e->key.keysym.sym == K_DOWN) {
				and_mem(CONTROLLER_BITFIELD, U5);
			}
		}
		if (e->type == SDL_QUIT) {
			stop_cpu();
		}
	}
}

