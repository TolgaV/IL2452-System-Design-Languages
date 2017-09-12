//monitor.h
//Monitor example http://electrosofts.com/systemC/index.html
#pragma once
#include "stdafx.h"
#include "systemc.h"

SC_MODULE(Monitor) {
	sc_in<int> a;
	sc_in<int> b;
	sc_in<int> c;		//problem before was setting c as an output port.
	sc_in<bool> clk;


	//its also possible to just prototype void the_monitor(){} here and put the content into monitor.cpp by including monitor.h
	//e.g. void Monitor::the_monitor(void){...} etc.
	void the_monitor() { 
		cout << " At " << sc_simulation_time() << " input is : ";
		cout << a << " , " << b << " output is : " << c << endl; }

	SC_CTOR(Monitor) {
		SC_METHOD(the_monitor);
		sensitive << a << b << c;// << clk.pos();
	}
};