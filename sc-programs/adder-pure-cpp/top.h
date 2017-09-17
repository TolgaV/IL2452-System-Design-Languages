#pragma once
#include "stdafx.h"
#include "adder.h"
#include "stimulus.h"
#include "monitor.h"

class Top : public sc_module {
public:
	/* Channels */
	sc_signal<int> siga;
	sc_signal<int> sigb;
	sc_signal<int> sigc;
	sc_clock testclk;

	/* Pointers for module instantiation */

	Adder *dut_inst;
	Monitor *mon_inst;
	Stimulus *stim_inst;

	/* Constructor */
	Top(sc_module_name _name);
	/* Destructor */
	//~Top();


};