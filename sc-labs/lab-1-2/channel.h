#pragma once
#include "stdafx.h"

/* Declaration of interface to Write to Channel */
class w_if : virtual public sc_interface{
public:
	virtual void write(char) = 0;
};
/* Declaration of interface to Read from Channel */
class r_if : virtual public sc_interface {
public:
	virtual void read(char&) = 0;
};

/* Definition of the channel */
class Hchan : public sc_module, public w_if, public r_if{
private:
	char carrier;
public:
	sc_port<w_if> input{ "channel input" };
	sc_port<r_if> output{ "channel output" };
	sc_in<bool> clock;

	Hchan(sc_module_name name) : sc_module(name) {
		input->write;
		output->read;
		carrier = NULL;
	}
	SC_HAS_PROCESS(Hchan);
	
	void write(char c);
	void read(char &c);
};