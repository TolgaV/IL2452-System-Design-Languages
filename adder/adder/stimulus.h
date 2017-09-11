//stimulus.h
#pragma once
#include "stdafx.h"
#include "systemc.h"

SC_MODULE(Stimulus) {
	sc_in<bool> clk;
	sc_out<int> a;
	sc_out<int> b;

	//declare process
	void generate();

	SC_CTOR(Stimulus) {
		//to test the design we use SC_THREAD instead
		//of SC_METHOD since SC_THREAD defines a process
		//that can be suspended by calling the wait() function
		SC_THREAD(generate);
		//sensitive to positive edge of clock
		//each call to wait() will suspend the process until
		//next positive edge of the clock
		//see stimulus.cpp for implementation
		sensitive << clk.pos();
	}
};