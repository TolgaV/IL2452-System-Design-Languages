// adder-pure-cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "adder.h"

Adder::Adder(sc_module_name _name)
	:sc_module(_name) {
	SC_THREAD(compute);
	//SC_METHOD(compute);
	sensitive << a, b;
}

void Adder::compute() {
	while (true) {
		wait(); //Because of wait output arrives in the next cycle
		//which is realistic, however looks ugly with current Monitor module.
		c = a + b;
	}
}