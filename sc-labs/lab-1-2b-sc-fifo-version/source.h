#pragma once
// file name = source.h
#include "stdafx.h"
class source : public sc_module {
public:
	//sc_port<w_if> out;
	sc_port<sc_fifo_out_if<char>, 0> out{ "sourceFifoOut" };
	//"sc_fifo_in<T>" is equivalent to "sc_port<sc_fifo_in_if<T>, 0>".
	sc_in<bool> clock;

	SC_HAS_PROCESS(source);

	source(sc_module_name name) : sc_module(name)
	{
		//out->write();
		SC_THREAD(source_p);
		sensitive << clock.pos();

	}

	void source_p();
};