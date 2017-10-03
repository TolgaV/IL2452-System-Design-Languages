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
		/* We can use read() method which belongs to r_if class since channel.h is included */
		
		in->read(c);
		c = (char)toupper(c);
		cout << endl << "Sink received: ";
		cout << c << flush;
		cout << endl;
		wait();
	}
}
