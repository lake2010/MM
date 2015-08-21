/*
 * Author: Xiangfu Liu <xiangfu@openmobilefree.net>
 * Bitcoin:	1CanaaniJzgps8EV6Sfmpb7T8RutpaeyFn
 *
 * This is free and unencumbered software released into the public domain.
 * For details see the UNLICENSE file at the root of the source tree.
 */

#include <stdint.h>

#include "intr.h"
#include "system_config.h"

#include "iic.h"
#include "timer.h"
#include "uart.h"

void isr(void)
{
	unsigned int irqs;

	irqs = irq_pending() & irq_getmask();

	if (irqs & IRQ_IIC)
		iic_isr();

	if (irqs & IRQ_TIMER0)
		timer0_isr();

	if (irqs & IRQ_TIMER1)
		timer1_isr();

	if (irqs & IRQ_UART)
		uart_isr();
}
