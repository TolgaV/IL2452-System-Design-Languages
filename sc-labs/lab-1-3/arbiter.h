#pragma once
#include "stdafx.h"

class Arbiter : public sc_module {
private:
	bool sel;
public:
	sc_in<bool> clock;
	sc_out<bool> select;

	void arbitrate();

	Arbiter(sc_module_name name) : sc_module(name) {
		sel = 0;
		SC_THREAD(arbitrate);
		sensitive << clock.pos();
	}
	SC_HAS_PROCESS(Arbiter);
};