//monitor.h
//Monitor example http://electrosofts.com/systemC/index.html
#pragma once
#include "stdafx.h"
#include "systemc.h"

SC_MODULE(Monitor) {
	sc_in<int> a;
	sc_in<int> b;
	sc_out<int> c;
	sc_in<bool> clk;

	void the_monitor() { 
		cout << " At " << sc_simulation_time() << " input is : ";
		cout << a << " , " << b << " output is : " << c << endl; }

	SC_CTOR(Monitor) {
		SC_METHOD(the_monitor);
		sensitive << a << b << clk.pos();
	}
};