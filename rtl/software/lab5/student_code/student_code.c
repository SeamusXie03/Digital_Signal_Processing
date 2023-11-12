// /*
//  * student_code.c
//  *
//  *  Created on: Mar 7, 2017
//  *      Author: user
//  */

#include <system.h>
#include <io.h>
#include "sys/alt_irq.h"
#include "student_code.h"
#include "altera_avalon_pio_regs.h"


#ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
void handle_lfsr_interrupts(void* context)
#else
void handle_lfsr_interrupts(void* context, alt_u32 id)
#endif
{
    #ifdef LFSR_VAL_BASE
    #ifdef LFSR_CLK_INTERRUPT_GEN_BASE
    #ifdef DDS_INCREMENT_BASE
    /* Read the edge capture register on interrupt. */
    alt_u32 edge_capture = IORD_ALTERA_AVALON_PIO_EDGE_CAP(LFSR_CLK_INTERRUPT_GEN_BASE);
    /* Read the LFSR bit 0 value. */
    alt_u32 lfsr_val = IORD_ALTERA_AVALON_PIO_DATA(LFSR_VAL_BASE);
    /* Check bit 0. */
    if (lfsr_val) {
        /* If LFSR bit 0 is 1, write the tuning word corresponding to 5 Hz. */
        IOWR_ALTERA_AVALON_PIO_DATA(DDS_INCREMENT_BASE, TUNING_WORD_5HZ);
    } else {
        /* If LFSR bit 0 is 0, write the tuning word corresponding to 1 Hz. */
        IOWR_ALTERA_AVALON_PIO_DATA(DDS_INCREMENT_BASE, TUNING_WORD_1HZ);
    }
    /* Reset the edge capture register. */
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(LFSR_CLK_INTERRUPT_GEN_BASE, 0);
    #endif
    #endif
    #endif
}

/* Initialize the button_pio. */

void init_lfsr_interrupt()
{
    #ifdef LFSR_VAL_BASE
    #ifdef LFSR_CLK_INTERRUPT_GEN_BASE
    #ifdef DDS_INCREMENT_BASE
    
    /* Enable interrupts */
    IOWR_ALTERA_AVALON_PIO_IRQ_MASK(LFSR_CLK_INTERRUPT_GEN_BASE, 0x1);
    /* Reset the edge capture register. */
    IOWR_ALTERA_AVALON_PIO_EDGE_CAP(LFSR_CLK_INTERRUPT_GEN_BASE, 0x0);
    /* Register the interrupt handler. */
    #ifdef ALT_ENHANCED_INTERRUPT_API_PRESENT
    alt_ic_isr_register(LFSR_CLK_INTERRUPT_GEN_IRQ_INTERRUPT_CONTROLLER_ID, LFSR_CLK_INTERRUPT_GEN_IRQ, handle_lfsr_interrupts, 0x0, 0x0);
    #else
    alt_irq_register( LFSR_CLK_INTERRUPT_GEN_IRQ, NULL,	handle_lfsr_interrupts);
    #endif
    
    #endif
    #endif
    #endif
}


