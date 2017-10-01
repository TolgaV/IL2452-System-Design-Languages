#include "stdafx.h"
#include "channel.h"

void Hchan::write(char c) {
	carrier = c;
	input->write(c);
	cout << "Written character is: " << c << endl;
}

void Hchan::read(char &c) {
	c = carrier;
	output->read(c);
	cout << "Character that is read is: " << c << endl;
}