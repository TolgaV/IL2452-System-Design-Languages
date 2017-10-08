// lab-2-1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "ram.h"

int sc_main(int argc, char *argv[])
{
	RandomAccessMemory RAM("myRAM",2048, 1);
	sc_start();

	return 0;
}

