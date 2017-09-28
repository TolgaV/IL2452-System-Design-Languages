#pragma once
#include "stdafx.h"

SC_MODULE(driver) {
	/* Declaring stimulus to OR gate's a and b inputs */
	sc_in<sc_bit> d_a;
	sc_in<sc_bit> d_b;

	void drivea();
	void driveb();

	SC_CTOR(driver) {
		SC_THREAD(drivea);
		SC_THREAD(driveb);
	}
};