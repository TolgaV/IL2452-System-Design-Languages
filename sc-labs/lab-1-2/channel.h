#pragma once
#include "stdafx.h"

class w_if : public sc_interface {
//Default access specifier is private so we have to
//explicitly state public.
public:
	virtual void cwrite(char) = 0;
};

class r_if : public sc_interface {
public:
	virtual void cread(char&) = 0;
};

class hchan : public sc_module, public w_if, public r_if {
private:
	char carrier;
public:
	hchan(sc_module_name name) : sc_module(name) {}
	SC_HAS_PROCESS(hchan);
	void cwrite(char c) {
		carrier = c;
	}
	void cread(char &c) {
	}
};