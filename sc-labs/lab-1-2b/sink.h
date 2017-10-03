#pragma once
// file name = sink.h
#include "stdafx.h"
#include"channel.h"
class sink : public sc_module {
public:
	sc_port<r_if> in{ "sinkInputPort" };
	sc_in<bool> clock;

	SC_HAS_PROCESS(sink);

	sink(sc_module_name name)
	{
		SC_THREAD(sink_p);
		sensitive << clock.pos();
	}

	void sink_p();
};