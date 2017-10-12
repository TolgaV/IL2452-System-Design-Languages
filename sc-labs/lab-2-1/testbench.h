#pragma once
#include "stdafx.h"
#include "ram.h"
//Notes:
///I should have defined RamAddress as an abstract base class
///with pure virtual functions in order to be able to use both
///with Testbench module and RAM module.
class Testbench : public sc_module {
public:
	sc_inout<sc_int<8>> tdata{ "T_DATA" };
	sc_in<sc_int<32>> taddress{ "T_ADDRESS" };
	sc_in<bool> ten{ "T_CE" };
	sc_in<bool> tmode{ "T_WE" };

	//When I inherit from RandomAccessMemory; Learn why I can't add sc_module name???, maybe indirect nonvirtual base class not allowed is the reason
	//Probably because sc_module is inherited twice
	void stim(void);
	void mon();

	RamAddress *tra;

	Testbench(sc_module_name name, int memory_size)
		:sc_module(name), tmemorySize(memory_size) {
		
		tra = new RamAddress(memory_size);
		tbInitialize();

		/*SC_THREAD(stim);
		sensitive << tdata, taddress;
		SC_THREAD(mon);
		sensitive << tdata, taddress;*/
	};
	SC_HAS_PROCESS(Testbench);

private:
	void tbInitialize();
	void fileIsRead(int&);

	/*void setData(std::string);
	void setAddress(sc_int<32> addr);
	void setEN(bool);
	void setMODE(bool);

	void resetData();
	void resetAddress();
	void resetEN();
	void resetMODE();
	*///sc_int<32> tmemorySize;

	sc_int<32> tmemorySize;					//SC Variable to keep size of RAM
	sc_int<32> tadres;						//SC Variable for offsetting p_dataAddress base pointer
	sc_int<32> tadresZero = 0;
};
