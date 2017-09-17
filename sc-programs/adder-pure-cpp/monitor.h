#pragma once
#include "stdafx.h"

class Monitor : public sc_module {
public:
	sc_in<bool> clock;
	sc_in<int> a, b, c;

	void watcher();
	Monitor(sc_module_name _name);
	SC_HAS_PROCESS(Monitor);

	//~Monitor();
};