#pragma once
// file name = sink.h
#include "stdafx.h"
class sink : public sc_module {
public:
	//sc_fifo_in is the port
	//sc_fifo is the primitive channel
	//sc_port<r_if> in;
	sc_port<sc_fifo_in_if<char>, 0> in{ "sinkFifoIn" };
	sc_in<bool> clock;

	SC_HAS_PROCESS(sink);

	sink(sc_module_name name)
	{
		SC_THREAD(sink_p);
		sensitive << clock.pos();
	}

	void sink_p();
};