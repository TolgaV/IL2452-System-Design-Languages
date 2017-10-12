// lab-2-1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ram.h"
#include "testbench.h"

int sc_main(int argc, char *argv[])
{
	int memSize = 20;
	//RandomAccessMemory RAM("myRAM", memSize, 1);
	Testbench("myRAMtb", memSize);
	sc_start();

	return 0;
}

//FINDING ABOUT NO RTTI DATA ERROR
///IT STOPS HAPPENING WHEN I ONLY INSTANTIATE TESTBENCH
///ITS MOST PROBABLY RELATED TO SC_THREAD(readRAM) and
///SC_THREAD(writeRAM) at RAM module and their implementations.