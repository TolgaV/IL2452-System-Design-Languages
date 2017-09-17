#include "stdafx.h"
#include "stimulus.h"

void Stimulus::generate() {
	/* Wait for posedge of clock */
	wait();
	a = 100, b = 100;
	wait();
	a = -200, b = 300;
	wait();
	a = 300, b = 400;
}

Stimulus::Stimulus(sc_module_name _name)
	:sc_module(_name) {
	SC_THREAD(generate);
	sensitive << clock.pos();	
}