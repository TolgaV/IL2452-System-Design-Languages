#pragma once
#include "stdafx.h"

class w_if : virtual public sc_interface {
public:
	virtual void write(char) = 0;
};

class r_if : virtual public sc_interface {
public:
	virtual void read(char&) = 0;
};

class Channel : public sc_module, public w_if, public r_if {
public:
	void write(char c);
	void read(char &c);

	void register_port(sc_port_base & port_, const char * if_typename_);

	Channel(sc_module_name name): sc_module(name){
		
	}
private:
	char temp;
};