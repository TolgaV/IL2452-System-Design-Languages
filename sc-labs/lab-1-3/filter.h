#pragma once
#include "stdafx.h"

class Filter : public sc_module {
private:
	char c;
	sc_event e1;
	sc_event e2;
public:
	//sc_port<sc_fifo_in_if<char>, 0> in{ "FilterIn" };
	sc_in<char> in;
	sc_port<sc_fifo_out_if<char>, 0> out{ "FilterOut" };
	sc_in<bool> clock{ "FilterClock" };

	void filterIt();
	void toBus();

	Filter(sc_module_name name) : sc_module(name) {
		SC_THREAD(filterIt);
		sensitive << clock.pos();
		SC_THREAD(toBus);
		//sensitive << clock.pos();
	}
	SC_HAS_PROCESS(Filter);
};