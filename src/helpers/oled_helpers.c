#include "oled_helpers.h"

void erase_oled() {
	gfx_mono_draw_string("             ", 0, 5, &sysfont);
	gfx_mono_draw_string("             ", 0, 16, &sysfont);
}

void draw_oled(char str[10]) {
	gfx_mono_draw_string(str, 0, 16, &sysfont);
}