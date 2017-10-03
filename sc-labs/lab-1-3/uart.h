#pragma once
#include "stdafx.h"

class Uart :public sc_module {
private:
	sc_event e1, e2;
	char c;
	char cOut;
public:
	sc_fifo_in<char> input;
	//sc_fifo_out<char> output;
	sc_out<char> output;
	sc_in<bool> clock;

	void receive();
	void transmit();

	Uart(sc_module_name name) :sc_module(name) {
		SC_THREAD(receive);
		sensitive << clock.pos();
		SC_THREAD(transmit);
		//sensitive << clock.pos();
	}
	SC_HAS_PROCESS(Uart);
};