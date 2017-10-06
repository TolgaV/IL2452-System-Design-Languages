#include "stdafx.h"
#include "ram.h"


void RandomAccessMemory::loadInitialize(){
	readFile();
}

void RandomAccessMemory::readFile() {
	/* Open the File */
	ifstream inFile;
	inFile.open("T1.txt");							//We can directly refer the file without absolute path since its in Resource Files.
	/* Check for an Error */
	if (inFile.fail()) {
		cerr << "Error Opening File\n";
		cout << "Check Stderr\n";
		exit(1);
	}
	std::string line;
	
	int i = 0;
	/* Loop reading until EOF or bad input */
	while (!inFile.eof()) {
		inFile >> memory[i];
		i++;
		if (i < memorySize) {
			continue;
		}
		else {
			cerr << "Address Out of Range\n";
			cout << "Check Stderr\n";
			SC_REPORT_ERROR("RAM", "Addresses that are out of range are not loaded!\n");
			break;
		}
	}
	inFile.close();
}

void RandomAccessMemory::read(){

}

void RandomAccessMemory::write() {

}