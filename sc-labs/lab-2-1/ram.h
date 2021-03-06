#pragma once
#include "stdafx.h"
#include <fstream> //Stream class to read from filesm, input file stream variable is called "ifstream"
#include <string>
class RamAddress {
public:
	//sc_int<16> *p_dataAddress;
	std::string *p_dataAddress;
	int *ram_address;
	bool *ram_address_valid;

	

	RamAddress(int mem_size) 
		:ram_memory_size(mem_size) {
		cout << " ram memory size is \n\n" << ram_memory_size;
		
		//p_dataAddress = new sc_int<16>[ram_memory_size];
		p_dataAddress = new std::string[ram_memory_size];
		ram_address_valid = new bool[ram_memory_size];
		ram_address = new int[ram_memory_size];
		
		cout << "\nRamAddress Object Created.\n";
	}
//private:
	int ram_memory_size;
};

class RandomAccessMemory : public sc_module {
public:
	sc_inout<sc_int<8>> data{ "DATA" };			//8-bit bidirectional data port
	sc_in<sc_int<32>> address{ "ADDRESS" };		//32-bit input address port
	//int address;//{ "ADDRESS" };
	sc_in<bool> en{ "CE" };						//Boolean input enable port
	sc_in<bool> mode{ "WE" };					//Boolean input mode (R/W) select port 

	RamAddress *ra;

	void readRAM();
	void writeRAM();
	/* Default Constructor */
	//RandomAccessMemory();
	//RandomAccessMemory(sc_module_name name, int memory_size);
	/* Initialize the constructor as RandomAccessMemory(name, size) */
	RandomAccessMemory(sc_module_name name, int memory_size, bool debug)
		:sc_module(name), memorySize(memory_size), debugFlag(debug) {
		
		ra = new RamAddress(memory_size);
		initFlag = true;
		cout << "\n\n\nLoading initial data... \n";
		loadInitialize();						//First call for filling memory array
		
		SC_THREAD(readRAM);
		sensitive << en, mode, data;
		SC_THREAD(writeRAM);
		sensitive << en, mode;
	}
	SC_HAS_PROCESS(RandomAccessMemory);			//Registering methods as SysC processes.
private:
	/* Private Member Functions */
	void loadInitialize();
	void readFile();
	void fileIsRead(int&);
	/* Private Data Members */
	bool enable;
	bool debugFlag;
	bool initFlag;
	//bool mode;
	
	//Data member for keeping memory size
	//int memorySize;
	sc_int<32> memorySize;					//SC Variable to keep size of RAM
	sc_int<32> adres;						//SC Variable for offsetting p_dataAddress base pointer
	sc_int<32> adresZero = 0;
};