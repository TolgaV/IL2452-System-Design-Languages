#pragma once
#include "stdafx.h"

SC_MODULE(monitor) {
	sc_in<sc_bit> m_a, m_b;
	sc_in<sc_bit> m_c;

	void prc_monitor();

	SC_CTOR(monitor) {
		SC_METHOD(prc_monitor);
		//sensitive << m_c;
		sensitive << m_a, m_b, m_c;
	}
};