// file name = sink.cpp
#include "stdafx.h"
#include "sink.h"
#include <cctype>
void sink::sink_p()
{
	char c;
	cout << endl << endl;

	while (true)
	{
		in->read(c);
		c = (char)toupper(c);
		cout << endl << "Sink received: ";
		cout << c << flush;
		cout << endl;
		wait();
	}
}
