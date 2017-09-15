#pragma once
#include "stdafx.h"
#include "systemc.h"

SC_MODULE(Counter) {
	sc_in<bool> clock, reset;
	sc_out<int> q;

	void count();

	SC_CTOR(Counter) {
		SC_THREAD(count);
		sensitive << clock, reset;
	}

private:
	int modulo = 5;
};

/*
class Counter : public sc_module {
public:
	sc_in<bool> clock, reset;
	sc_out<int> q;

	Counter::Counter(sc_module_name name, int mod)
		:sc_module(name), cnt(0), modulo(mod) {
		SC_THREAD(count);
		sensitive << clk.pos();
	}
	SC_HAS_PROCESS(Counter);
private:
	void count();
	int cnt;
	const int modulo;
};
*/