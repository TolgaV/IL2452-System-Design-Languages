#pragma once
#include "stdafx.h"
//cctype library is included in orer to use toupper() method
#include <cctype>

class ChangeCase : public sc_module {
private:
	char c;
	sc_event e1;	//input is read to c
	sc_event e2;	//output is written to bus
public:
	//sc_port<sc_fifo_in_if<char>, 0> in{ "ChangeCaseIn" };
	sc_in<char> in;
	sc_port<sc_fifo_out_if<char>, 0> out{ "ChangeCaseOut" };
	sc_in<bool> clock{ "ChangeCaseClock" };

	void upCase();
	void toBus();

	ChangeCase(sc_module_name name) : sc_module(name) {
		SC_THREAD(upCase);
		sensitive << clock.pos();
		SC_THREAD(toBus);
		//sensitive << clock.pos();
	}
	SC_HAS_PROCESS(ChangeCase);
};