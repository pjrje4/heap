#include <iostream>
#include "heap.h"
#include <cstring>
#include <fstream>

#if 0
Justin Iness
4/5/2022
C++ Programming
Heap
#endif

using namespace std;

int main() {
	Heap* h = new Heap(100); // new heap size 100 per requirements
	char input[5000];
	cout << "(FILE) or Command Line (INPUT)" << endl;
	cin.getline(input, 10);
	if (strcmp(input, "INPUT") == 0) { // input through command line
		cout << "Enter numbers separated by spaces:" << endl;
		cin.getline(input, 5000);
		//make a new file and write all the numbers to it
		fstream iFile;
		iFile.open("thisisthestupidestwaytodothisbutimsickandlazy.txt", ios::out | ios::trunc);
		if (!iFile) { 
			cout << "Can't find thisisthestupidestwaytodothisbutimsickandlazy.txt.  Make sure you download it from my repo." << endl;
			return 0;
		}
		else {
			iFile << input;
			iFile.close();
		}
		// then read the numbers from it using the >> operator
		// I did this whole thing because I wanted to read in my numbers using >>
		// help me
		iFile.open("thisisthestupidestwaytodothisbutimsickandlazy.txt", ios::in);
		int number = 0;
		while (iFile >> number) {
			if (number != 0) {
				h->addNum(number); // add to heap
			}
		}
	}
	if (strcmp(input, "FILE") == 0) {
		fstream iFile;
		cout << "What is the file's name?" << endl;
		cin >> input;
		// open file and read numbers from it
		iFile.open(input, ios::in);
		if (!iFile) {
			cout << "Can't find " << input << ".  Try including .txt?" << endl;
			return 0;
		}
		else {
			cout << "opened file" << endl;
			int number = 0;
			while (iFile >> number) {
				if (number != 0) {
					h->addNum(number); // add to heap
				}
			}
		}	
	}
	h->print(1); // print heap from root
	h->out(); // output least to greatest
	return 0;
}
