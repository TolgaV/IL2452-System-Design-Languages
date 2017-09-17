// adder-pure-cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "adder.h"

Adder::Adder(sc_module_name _name)
	:sc_module(_name) {
	SC_THREAD(compute);
	sensitive << a, b;
}

void Adder::compute() {
	while (true) {
		wait();
		c = a + b;
	}
}