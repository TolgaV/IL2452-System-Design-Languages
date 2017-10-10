#pragma once
#include "stdafx.h"
#include <fstream>
#include <string>
#include "ram.h"
class RAMtestbench : public sc_module{//, public RandomAccessMemory{
public:
	sc_inout<sc_int<8>> tdata{ "T_DATA" };
	sc_in<sc_int<32>> taddress{ "T_ADDRESS" };
	sc_in<bool> ten{ "T_CE" };
	sc_in<bool> tmode{ "T_WE" };

	void stimulus();
	void monitor();

	RAMtestbench(sc_module_name name, int tmemory_size)
		:sc_module(name), tmemorySize(tmemory_size) {
		SC_THREAD(stimulus);
		sensitive << tdata, taddress;
		SC_THREAD(monitor);
		sensitive << tdata, taddress;
	}
	SC_HAS_PROCESS(RAMtestbench);


private:
	void setData(std::string);
	void setAddress(sc_int<32> addr);
	void setEN(bool);
	void setMODE(bool);

	void resetData();
	void resetAddress();
	void resetEN();
	void resetMODE();
	//sc_int<32> tmemorySize;
	int tmemorySize;
};