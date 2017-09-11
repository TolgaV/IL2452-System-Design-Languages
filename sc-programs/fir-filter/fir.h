//fir.h
#pragma once
#include <systemc.h>
SC_MODULE(Fir) {

	sc_in<bool>			clk;
	sc_in<bool>			rst;
	sc_in<sc_int<16>>	inp;
	sc_out<sc_int<16>>	outp;

	void fir_main();

	SC_CTOR(Fir) {
		SC_CTHREAD(fir_main, clk.pos());
		reset_signal_is(rst, true);
	}
};

//coefficients for each FIR
const sc_uint<8> coef[5] = {
	18,
	77,
	107,
	77,
	18
};