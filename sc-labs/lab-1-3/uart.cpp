#include "stdafx.h"
#include "uart.h"
/* Double Check the methods below */
void Uart::receive() {
	for (;;) {
		wait();
		input->read(c);
		/* This part may be problematic */
		e1.notify();
		wait(e2);
	}
	

}

void Uart::transmit() {
	for (;;) {
		wait(e1);
		output->write(c);
		e2.notify();
	}
}