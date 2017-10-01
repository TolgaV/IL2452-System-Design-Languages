#pragma once
#include "stdafx.h"

SC_MODULE(driver) {
	/* Declaring stimulus to OR gate's a and b inputs */
	//sc_in<sc_bit> d_a;
	//sc_in<sc_bit> d_b;
	sc_out<sc_bit> d_a;
	sc_out<sc_bit> d_b;

	void drivea();
	void driveb();

	SC_CTOR(driver) {
		//When there is no clock its pointless to use SC_METHOD
		/*
		SC_METHOD(drivea);
		SC_METHOD(driveb);
		*/

		SC_THREAD(drivea);
		SC_THREAD(driveb);
	}
};