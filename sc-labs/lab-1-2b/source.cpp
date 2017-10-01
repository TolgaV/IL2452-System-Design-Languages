// file name = source.cpp
#include "stdafx.h"
#include "source.h"
#include <iostream>
#include <iomanip>

using namespace std;

void source::source_p()
{
	const char *alphabet =
		"abcdefghijklmnopqrstuvwxyz\n";

	while (*alphabet)
	{
		out->write(*alphabet++);
		wait();
	}
	std::cout << "************************************" << endl;
	std::cout << std::setw(10) << "END OF STRING" << endl;
	std::cout << "************************************" << endl;
	cin.get();
	system("pause");
}