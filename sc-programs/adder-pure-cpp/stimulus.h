#pragma once
#include "stdafx.h"

class Stimulus : public sc_module {
public:
	sc_in<bool> clock;
	sc_out<int> a, b;

	/* Method to be defined */
	void generate();
	
	/* Constructor to be defined */
	Stimulus(sc_module_name _name);
	SC_HAS_PROCESS(Stimulus);
	/* Destructor to be defined */
	~Stimulus();
};