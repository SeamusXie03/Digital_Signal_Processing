/*
 * student_code.h
 *
 *  Created on: Mar 7, 2017
 *      Author: user
 */

#ifndef STUDENT_CODE_H_
#define STUDENT_CODE_H_
#include <system.h>
#include <io.h>
#include "sys/alt_irq.h"
#include "altera_avalon_pio_regs.h"

#define TUNING_WORD_1HZ 86     /* Pre-calculated 1 Hz tuning word */
#define TUNING_WORD_5HZ 429    /* Pre-calculated 5 Hz tuning word */

#ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
void handle_button_interrupts(void* context);
#else
void handle_lfsr_interrupts(void* context, alt_u32 id);
#endif

void init_lfsr_interrupt();



#endif /* STUDENT_CODE_H_ */
