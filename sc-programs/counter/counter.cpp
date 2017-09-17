// counter.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "counter.h"
#include <iostream>
#include <systemc.h>

Counter::Counter(sc_module_name _name, int _mod, int _cnt)
	:sc_module(_name), mod(_mod), cnt(0) {
	SC_METHOD(count);
	sensitive << clk.pos();
}

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
	/*
		cnt++;
	while (true) {
		wait();
		std::cout << "Count is: " << cnt << endl;
		if (reset == true) {
			cnt = 0;
		}
		else {
			cnt++;
			if (cnt == modulo) cnt = 0;
		}
		q = cnt;
	}
}*/


	/* THREAD VERSION */
/*/
Counter::Counter(sc_module_name name, int mod)
	:sc_module(name), cnt(0), modulo(mod) {
		sensitive << clk.pos();
}*/