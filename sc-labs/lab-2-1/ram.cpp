#include "stdafx.h"
#include "ram.h"


void RandomAccessMemory::loadInitialize(){
	readFile();
}

void RandomAccessMemory::readFile() {
	
	ifstream inFile;
	inFile.open("T1.txt");

	if (!inFile) {
		cout << "\nUnable to open file!\n";
		exit(1);
	}
	int i = 0;
	/* Loop reading until EOF or bad input */
	while (inFile >> memory[i]) {					//CHANGE THIS TO READING LINES ; getline(cin, s); where s is a string and then parse do some stuff.
		i++;
		if (i < memorySize)
			continue;
		else 
			break;
	}
	inFile.close();
}

void RandomAccessMemory::read(){

}

void RandomAccessMemory::write() {

}