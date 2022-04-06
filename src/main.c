#include <asf.h>
#include "helpers/helpers.h"
#include "helpers/defines.h"
#include "helpers/oled_helpers.h"
#include "helpers/extra_helpers.h"

#include "oled/gfx_mono_ug_2832hsweg04.h"
#include "oled/gfx_mono_text.h"
#include "oled/sysfont.h"

volatile char but1_flag;
volatile char but2_flag;
volatile char but3_flag;
volatile char alarm_rtt = 0;

void all_flags_zero() {
	but1_flag = 0;
	but2_flag = 0;
	but3_flag = 0;
}

void but1_callback(void) {
	but1_flag = 1;
}

void but2_callback(void) {
	but2_flag = 1;
}

void but3_callback(void) {
	but3_flag = 1;
}

/************************************************************************/
/* handlers                                                              */
/************************************************************************/

void RTT_Handler(void) {
	uint32_t ul_status;

	ul_status = rtt_get_status(RTT);
	
	//alarm
	if ((ul_status & RTT_SR_ALMS) == RTT_SR_ALMS) {
		alarm_rtt = 1;
	}
	
	//time
	if ((ul_status & RTT_SR_RTTINC) == RTT_SR_RTTINC) {
		//TODO
	}

}

void TC0_Handler(void) {
	
	volatile uint32_t status = tc_get_status(TC0, 0);
	//TODO
}

void TC1_Handler(void) {
	
	volatile uint32_t status = tc_get_status(TC0, 1);
	//TODO
}

/************************************************************************/
/* init                                                              */
/************************************************************************/

void io_init(void) {
	pmc_enable_periph_clk(LED1_PIO_ID);
	pmc_enable_periph_clk(LED2_PIO_ID);
	pmc_enable_periph_clk(LED3_PIO_ID);
	pio_configure(LED1_PIO, PIO_OUTPUT_1, LED1_IDX_MASK, PIO_DEFAULT);
	pio_configure(LED2_PIO, PIO_OUTPUT_1, LED2_IDX_MASK, PIO_DEFAULT);
	pio_configure(LED3_PIO, PIO_OUTPUT_1, LED3_IDX_MASK, PIO_DEFAULT);
	
	config_button(BUT1_PIO, BUT1_IDX_MASK, BUT1_PIO_ID, but1_callback, 1, 1);
	config_button(BUT2_PIO, BUT2_IDX_MASK, BUT2_PIO_ID, but2_callback, 1, 1);
	config_button(BUT3_PIO, BUT3_IDX_MASK, BUT3_PIO_ID, but3_callback, 1, 1);
}

int main(void) {
	
  board_init();
  sysclk_init();
  delay_init();
  io_init();
  gfx_mono_ssd1306_init();
	
	TC_init(TC0, ID_TC0, 0, 5);
	TC_init(TC0, ID_TC1, 1, 2);

  
  while (1) {
		//TODO
	}
}
