#pragma once
#include "stdafx.h"
#include "channel.h"

class sink : public sc_module {
public:
	sc_port<r_if> in;
	sc_in<bool> clock;
	

	sink(sc_module_name name) {
		SC_THREAD(sink_p);
		sensitive << clock.pos();
	}
	SC_HAS_PROCESS(sink);

	void sink_p();
};