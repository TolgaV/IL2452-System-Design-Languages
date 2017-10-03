#pragma once
#include "stdafx.h"

class Bus : public sc_module {
private:
	bool sel;
	char c1;
	char c2;
	char cOut;
public:
	sc_port<sc_fifo_in_if<char>, 0> inM1{ "busM1in" };
	//sc_fifo_in<char> inM1;
	sc_port<sc_fifo_in_if<char>, 0> inM2{ "busM2in" };
	sc_in<bool> inM3{ "busM3in" };
	sc_in<bool> clock{ "FilterClock" };
	
	sc_port<sc_fifo_out_if<char>, 0> outM5{ "busUART" };

	void mux();

	Bus(sc_module_name name) :sc_module(name) {
		SC_THREAD(mux);
		sensitive << clock.pos();
	}
	SC_HAS_PROCESS(Bus);
};