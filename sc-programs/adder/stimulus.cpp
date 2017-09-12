//stimulus.cpp
#include "stdafx.h"
#include "stimulus.h"

//define implementation of process generate
void Stimulus::generate() {
	wait();				//wait for positive edge of clock
	a = 100; b = 100;	//test inputs for a and b
	wait();				//wait for positive edge of clock
	a = -100; b = -200;
	wait();
	a = 100; b = -100;
	wait();
	
	//system("pause");

	sc_stop();			//stop simulation
}