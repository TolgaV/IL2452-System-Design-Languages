#include "stdafx.h"
#include "ram.h"


void RandomAccessMemory::loadInitialize(){
	if (initFlag) {
		cout << "\n\nYEEEES\n\n";
		readFile();
	}
	else {
		cout << "\n\nNOOOOOO\n\n";
		//fileIsRead();
	}
}

void RandomAccessMemory::readFile() {
	/* Open the File */
	ifstream inFile;
	inFile.open("Resources/T1.txt");							//We can directly refer the file without absolute path since its in Resource Files.
	/* Check for an Error */
	if (!inFile) {
		cout << "\nUnable to Load File...\n\n";
		exit(1);
	}

	int i = 0;
	bool eofFlag = false;
	std::string line;
	std::string subline;

	cout << "ADDR\tV\tDATA\t\n";
	cout << "--------------------------\n";
	/* Loop reading until EOF or bad input */
	while (!inFile.bad() && (i < memorySize)){
		std::getline(inFile, line);
		if (inFile.eof()) {
			eofFlag = true;
			cout << "MOUHAHAHAHAHA - EOOOOOOF\n";
			if (eofFlag)
				fileIsRead(i);
		}
		/* Body of Function to be Disabled after Calling fileIsRead() */
		if (!eofFlag) {
			int j = line.length();		
			//cout << j << "\t";	//For out of range exception
			if ((j < 8) && (j > 3)) {
				subline = line.substr((line.length() - 2), line.length());
			}

			/* Initializing RAM */
			ra->p_dataAddress[i] = subline;
			ra->ram_address_valid[i] = true;
			ra->ram_address[i] = i;
			cout << *(ra->ram_address + i) << "\t" << *(ra->ram_address_valid + i) \
				<< "\t" << *(ra->p_dataAddress + i) << "\t" << sizeof(subline) << "\t\n";

			i++;
		}
		/*if (i < memorySize) {
			continue;
		}
		else {
			cerr << "\nAddress Out of Range\n";
			cout << "Check Stderr\n";
			SC_REPORT_ERROR("RAM", "Addresses that are out of range are not loaded!\n");
			break;
		}*/
	}
	inFile.close();
	initFlag = 0;
}

void RandomAccessMemory::fileIsRead(int &i) {
	std::string unavailable = "XX";
	while (i < memorySize) {
		ra->p_dataAddress[i] = unavailable;
		ra->ram_address_valid[i] = false;
		ra->ram_address[i] = i;
		
		cout << *(ra->ram_address + i) << "\t" << *(ra->ram_address_valid + i) \
			<< "\t" << *(ra->p_dataAddress + i) << "\n";// << "\t" << sizeof(subline) << "\t\n";
		i++;
	}
	cout << "OOOOOOOOOOOOOOOOOOOOOOOOOOOOO";
}

void RandomAccessMemory::read(){
/*	while (true) {
		
		en false;
	
	adsdsadasds
		if(this->en)
	}*/
}

void RandomAccessMemory::write() {
	
}