//adder.h
#pragma once
#include "stdafx.h"
#include "systemc.h"

SC_MODULE(Adder) {
	//ports
	sc_in<int> a;
	sc_in<int> b;
	sc_out<int> c;

	//process declaration
	void compute();

	//constructor
	SC_CTOR(Adder) {
		//define sensitivity and type of the process
		SC_METHOD(compute);
		sensitive << a << b;
	}
};
//its also possible to move the constructor to adder.cpp