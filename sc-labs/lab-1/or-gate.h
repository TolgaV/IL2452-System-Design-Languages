#pragma once
#include "stdafx.h"

SC_MODULE(or_gate) {
	sc_in<sc_bit> a;
	sc_in<sc_bit> b;
	sc_out<sc_bit> c;


	void prc_or_gate();

	SC_CTOR(or_gate) {
		SC_METHOD(prc_or_gate);

		//in the Stimulus we change a and b at the same time, that is why we see wrong output (0 is outputted twice) so ignoring first output would've solved it
		sensitive << a << b;
	}
};