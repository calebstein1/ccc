#ifndef CCC_CONTROLLER_H
#define CCC_CONTROLLER_H

#define CONTROLLER_BITFIELD (prg_ram[0x4001])

#define K_PRIMARY SDLK_x
#define K_SECONDARY SDLK_z
#define K_LEFT SDLK_LEFT
#define K_RIGHT SDLK_RIGHT
#define K_UP SDLK_UP
#define K_DOWN SDLK_DOWN

void get_controller_state(SDL_Event *e);

#endif
