#pragma once
#include "stdafx.h"

SC_MODULE(or_gate) {
	sc_in<sc_bit> a;
	sc_in<sc_bit> b;
	sc_out<sc_bit> c;


	void prc_or_gate();

	SC_CTOR(or_gate) {
		SC_METHOD(prc_or_gate);
		sensitive << a << b;
	}
};