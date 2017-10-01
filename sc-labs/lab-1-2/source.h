#pragma once
#include "stdafx.h"
#include "channel.h"

class source : public sc_module {
public:
	sc_port<w_if> out;
	sc_in<bool> clock;


	source(sc_module_name name) : sc_module(name) {
		SC_THREAD(source_p);
		sensitive << clock.pos();
	}
	SC_HAS_PROCESS(source);

	void source_p();
};