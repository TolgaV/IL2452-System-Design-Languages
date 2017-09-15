// counter.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "counter.h"
#include <iostream>

void Counter::count() {
	int cnt = 0;
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
}
/*/
Counter::Counter(sc_module_name name, int mod)
	:sc_module(name), cnt(0), modulo(mod) {
		sensitive << clk.pos();
}*/