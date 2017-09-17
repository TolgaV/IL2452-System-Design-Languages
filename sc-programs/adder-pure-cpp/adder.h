#pragma once
#include "stdafx.h"
#include "systemc.h"

class Adder :public sc_module {
public:
	sc_in<int> a;
	sc_in<int> b;
	sc_out<int> c;

	void compute();

	Adder(sc_module_name _name) :sc_module(_name) {};
	SC_HAS_PROCESS(Adder);
};