#pragma once
#include "stdafx.h"
#include <fstream> //Stream class to read from filesm, input file stream variable is called "ifstream"

//Maybe use a struct to keep address thingy.sfgdfzxnhgc,'j;lghmh;kcfnb;kxfthnb.x,knb
class RamAddress {
public:
	int *ram_address;
	char *ram_data;

	RamAddress(int size) :ram_memory_size(size) {
		ram_address = new int[ram_memory_size];
		ram_data = new char[ram_memory_size];
	}
private:
	int ram_memory_size;
};

class RandomAccessMemory : public sc_module {
public:
	sc_inout<sc_int<8>> data{ "DATA" };			//8-bit bidirectional data port
	sc_in<sc_int<32>> address{ "ADDRESS" };		//32-bit input address port
	sc_in<bool> en{ "CE" };						//Boolean input enable port
	sc_in<bool> mode{ "WE" };					//Boolean input mode (R/W) select port 

	char *memory;								//Pointer to memory
	RamAddress *ra;				///////////////////////////////////////////////////////////////////CONTINUE FROM HERE, GOT TO INSTANTIATE THIS IN THE CONSTRUCTOR AND FIND A WAY TO READ FILE INTO ITS MEMBERS USING loadInitiaize();

	void read();
	void write();

	//Initialize the constructor as RandomAccessMemory(name, size)
	RandomAccessMemory(sc_module_name name, int size) :sc_module(name), memorySize(size) {
		memory = new char[memorySize];

		cout << "\n\n\nLoading initial data... \n";
		loadInitialize();

		int *address = new int[memorySize];		//Array to keep address values
		ra = new RamAddress(size);
		ra->ram_address = somechar here, this assignment to be done via the function;
	}
	
	~RandomAccessMemory() {
		delete [] memory;
	}

private:
	/* Private Member Functions */
	void loadInitialize();
	void readFile();

	/* Private Data Members */
	bool enable;
	bool mode;
	//sc_int<32> address;
	//sc_int<8> data;
	
	//Data member for keeping memory size
	int memorySize;
};