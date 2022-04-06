#include <iostream>
#include "heap.h"
#include <cstring>
#include <fstream>

using namespace std;

int main() {
	Heap* h = new Heap(100);
	char input[5000];
	cout << "(FILE) or Command Line (INPUT)" << endl;
	cin >> input;
	if (strcmp(input, "INPUT") == 0) {
		cout << "Enter numbers separated by spaces:" << endl;
		int count = 0;
		int number = 0;
		while (cin >> number) {
			cout << number << endl;
			if (number != 0) {
				h->addNum(number);
			}
			/*count++;
			if (count <= 100) {
				break;
			}*/
			cout << "count: " << count << endl;
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
