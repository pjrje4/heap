#include <iostream>
#include <cstring>
#include "heap.h"

#if 0
Justin Iness
3/28/2022
C++ Programming
Heap
#endif

using namespace std;

Heap::Heap(int size) { // parametized constructor
	currentSize = 0;
	maxSize = size;
	data = new int[size];
}
Heap::~Heap() { // destructor
}
//getters and setters
void Heap::addNum(int num) {
	int i = 1;
	while (data[i] != NULL) {
		i++;
	}
	data[i] = num;
	if 
}
void Heap::delNum() {
	return;
}
void Heap::print() {
	return;
}
