#ifndef EXTRAHELPERS_H_   /* Include guard */
#define EXTRAHELPERS_H_
#include <asf.h>
#include "defines.h"

static uint32_t get_time_rtt();
void pin_toggle(Pio *pio, uint32_t mask);
void toggle_all();
void all_leds_on();
void all_leds_off();

#endif