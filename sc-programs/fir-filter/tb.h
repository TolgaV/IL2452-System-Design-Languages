//tb.h
#pragma once
#include "stdafx.h"
#include <systemc.h>

SC_MODULE(Tb) {
	sc_in<bool>	clk;
	sc_out<bool> rst;			//reset is out since we source it from testbench
	sc_out<sc_int<16>> inp;		//inp is out since we source it from testbench
	sc_in<sc_int<16>> outp;		//outp is in since we sink it to testbench

	void source();
	void sink();

	SC_CTOR(Tb) {
		SC_CTHREAD(source, clk.pos());
		SC_CTHREAD(sink, clk.pos());
	}
};