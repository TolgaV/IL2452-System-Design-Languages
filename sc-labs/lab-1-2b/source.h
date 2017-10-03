#pragma once
// file name = source.h
#include "stdafx.h"
#include"channel.h"
class source : public sc_module {
public:
	sc_port<w_if> out{ "sourceOutputPort" };
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