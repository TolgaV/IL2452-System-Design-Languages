#include "stdafx.h"
#include "testbench.h"


void Testbench::stim() {
	wait();
}
void Testbench::mon() {
	wait();
}

void Testbench::tbInitialize() {
	/* Open the File */
	cout << "TESTBENCH_TESTBENCH_TESTBENCH\n";

	ifstream tinFile;
	tinFile.open("Resources/T2.txt");							//We can directly refer the file without absolute path since its in Resource Files.
																/* Check for an Error */
	if (!tinFile) {
		cout << "\nUnable to Load File...\n\n";
		exit(1);
	}

	int i = 0;
	bool eofFlag = false;
	std::string tline;
	std::string subline;

	cout << "ADDR\tV\tDATA\t\n";
	cout << "--------------------------\n";
	/* Loop reading until EOF or bad input */
	while (!tinFile.bad() && (i < tmemorySize)) {
		std::getline(tinFile, tline);
		if (tinFile.eof()) {
			eofFlag = true;
			cout << "MOUHAHAHAHAHA - EOOOOOOF\n";
			if (eofFlag)
				fileIsRead(i);
		}
		/* Body of Function to be Disabled after Calling fileIsRead() */
		if (!eofFlag) {
			int j = tline.length();
			//cout << j << "\t";	//For out of range exception
			if ((j < 8) && (j > 3)) {
				subline = tline.substr((tline.length() - 2), tline.length());
			}

			/* Initializing RAM */
			tra->p_dataAddress[i] = subline;
			tra->ram_address_valid[i] = true;
			tra->ram_address[i] = i;
			cout << *(tra->ram_address + i) << "\t" << *(tra->ram_address_valid + i) \
				<< "\t" << *(tra->p_dataAddress + i) << "\t" << sizeof(subline) << "\t\n";

			i++;
		}
	}
	tinFile.close();
}


void Testbench::fileIsRead(int &i) {
	std::string unavailable = "XX";
	while (i < tmemorySize) {
		tra->p_dataAddress[i] = unavailable;
		tra->ram_address_valid[i] = false;
		tra->ram_address[i] = i;

		cout << *(tra->ram_address + i) << "\t" << *(tra->ram_address_valid + i) \
			<< "\t" << *(tra->p_dataAddress + i) << "\n";// << "\t" << sizeof(subline) << "\t\n";
		i++;
	}
	cout << "TESTTESTTESTTESTTESTTESTTESTTESTTESTTEST";
}