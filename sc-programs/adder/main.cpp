//main.cpp
#include "stdafx.h"
#include "systemc.h"
#include "top.h"
#include "monitor.h"

int sc_main(int argc, char* argv[]) {
	Top top("top");
	
	sc_start();

	return 0;
}