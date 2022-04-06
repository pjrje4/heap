#include <iostream>
#include "heap.h"
#include <cstring>
#include <fstream>

using namespace std;

int main() {
	Heap* h = new Heap(100);
	char input[5000];
	cout << "(FILE) or Command Line (INPUT)" << endl;
	cin.getline(input, 10);
	if (strcmp(input, "INPUT") == 0) {
		cout << "Enter numbers separated by spaces:" << endl;
		cin.getline(input, 5000);
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
		iFile.open("thisisthestupidestwaytodothisbutimsickandlazy.txt", ios::in);
		int number = 0;
		while (iFile >> number) {
			if (number != 0) {
				h->addNum(number);
			}
		}
	}
	if (strcmp(input, "FILE") == 0) {
		fstream iFile;
		cout << "What is the file's name?" << endl;
		cin >> input;
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
					h->addNum(number);
				}
			}
		}	
	}
	h->print(1);
	h->out();
	return 0;
}
