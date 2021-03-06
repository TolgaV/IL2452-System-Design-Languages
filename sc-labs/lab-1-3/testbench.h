#pragma once
// file name = testbench.h
#include "stdafx.h"
#include"systemc.h"

SC_MODULE(driver)
{
	sc_out<char> d_char1, d_char2; // char generator
	//sc_fifo_out<char> d_char;
	void prc_drive();


	SC_CTOR(driver)
	{
		SC_THREAD(prc_drive);
	}
};

SC_MODULE(monitor)
{
	sc_in<char> m_char;
	//sc_fifo_in<char> m_char;
	void prc_monitor();

	SC_CTOR(monitor)
	{
		SC_METHOD(prc_monitor);
		sensitive << m_char;
	}
};