// counter.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "counter.h"
#include <iostream>
#include <systemc.h>

/* Constructor moved to counter.cpp, for pure C++ implementation */
/*
Counter::Counter(sc_module_name _name, int _mod, int _cnt)
	:sc_module(_name), modulo(5), cnt(0) {
	SC_METHOD(count);
	sensitive << clock.pos();
}
*/
/* Definition of count() method */
	/* METHOD VERSION */
/*
void Counter::count() {
		
	if (reset == true)
		cnt = 0;
	else {
		cnt++;
		if (cnt == modulo)
			cnt = 0;
	}
	q = cnt;
	std::cout << "Count is: " << q << "at time: " << sc_time_stamp() << endl;
}
*/
	/* THREAD VERSION */

void Counter::count() {
	while (true) {
		wait();
		if (reset == true)
			cnt = 0;
		else
			if (cnt == modulo)
				cnt = 0;
			else
				cnt++;
		q = cnt;
		std::cout << "Count is: " << q << "at time: " << sc_time_stamp() << endl;

	}
}