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
	cout << "RAM_RAM_RAM_RAM_RAM_RAM\n";
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

void RandomAccessMemory::readRAM() {
	//int adres = 0;
	///sc_int<32> adres = 0;
	for (;;)
	{
		wait();
		/* Check Address Range since sc_int < int doesn't work; I use sc_int<32>(0) */
		if ( (this->address >= this->memorySize) || (/*this->address*/address.read() < this->adresZero) ) {
			cerr << "\nAddress Out of Range\n";
			cout << "Check Stderr\n";
			SC_REPORT_ERROR("RAM", "Addresses that are out of range are not loaded!\n");
		}
		else continue;
		/* Check Mode, is WE == 0 */
		//if (this->mode == 1) {
		//if (mode == 1) {
		if (mode.read() == 0) {										//IF WE = 0
			if (en.read() == 0) {									//IF CE = 0
				this->data = 0xFF;									//DATA = 0XFF
			}
			else {													//IF CE = 1
				adres = this->address;
				//Set data port with the content at address
				this->data = std::stoi(ra->p_dataAddress[adres]);	//DATA = ADDRESS[ADRES]
				//this->data = ra->p_dataAddress[adres];
			}
		}
		else {
			//wait();
		}
	}
}

void RandomAccessMemory::writeRAM() {
	//int adres = 0;
	bool discard = false;
	for (;;)
	{
		wait();
		/* Check Address Range */
		if ( (this->address >= this->memorySize) || (this->address < this->adresZero) ) {
			cerr << "\nAddress Out of Range\n";
			cout << "Check Stderr\n";
			SC_REPORT_ERROR("RAM", "Addresses that are out of range are not loaded!\n");
		}
		else continue;
		/* Check Mode, is WE == 0 */
		if (this->mode == 1) {										//IF WE = 1
			if (this->en == 0) {									//IF CE = 0
				discard = true;										//DISCARD OPERATION
			}
			else {
				if (!discard) {
					adres = this->address;
					this->data = std::stoi(ra->p_dataAddress[adres]);
					//ra->p_dataAddress[adres] = this->data;
				}
				else
					cout << "\nWrite Operation Requested is discarded since CE was set to 0\n";
			}
		}
		else {
			//wait();
		}
	}
}