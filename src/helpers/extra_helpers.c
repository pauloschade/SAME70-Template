#include "extra_helpers.h"

void pin_toggle(Pio *pio, uint32_t mask) {
	pio_get_output_data_status(pio, mask) ? pio_clear(pio, mask) : pio_set(pio,mask);
}

void toggle_all() {
	pin_toggle(LED1_PIO, LED1_IDX_MASK);
	pin_toggle(LED2_PIO, LED2_IDX_MASK);
	pin_toggle(LED3_PIO, LED3_IDX_MASK);
}

void all_leds_on() {
	pio_clear(LED1_PIO, LED1_IDX_MASK);
	pio_clear(LED2_PIO, LED2_IDX_MASK);
	pio_clear(LED3_PIO, LED3_IDX_MASK);
}

void all_leds_off() {
	pio_set(LED1_PIO, LED1_IDX_MASK);
	pio_set(LED2_PIO, LED2_IDX_MASK);
	pio_set(LED3_PIO, LED3_IDX_MASK);
}