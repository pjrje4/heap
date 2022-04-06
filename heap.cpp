#include <iostream>
#include <cstring>
#include <math.h>
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
	maxSize = size + 1;
	data = new int[size + 1];
	for (int i = 0; i < size+1; i++) {
		data[i] = 0;
	}
}
Heap::~Heap() { // destructor
}
void Heap::debug() { // to debug the array
	cout << endl;
	for (int i = 0; i < maxSize; i++) {
		cout << data[i] << ", ";
	}
	cout << "debug" << endl;
}
int Heap::left(int index) { // left
	return index*2;
}
int Heap::right(int index) { // right
	return index*2+1;
}
int Heap::parent(int index) { // parent of index
	return index/2;
}
void Heap::swap(int x, int y) { // swap 2 index
	int temp = data[x];
	data[x] = data[y];
	data[y] = temp;
}

void Heap::addNum(int num) { // add a number
	int i = 1;
	while (data[i] != 0) {
		i++;
	}
	data[i] = num;
	swim(i); // make sure not broken
	currentSize++;
	return;
}
void Heap::out() { // output whole thing
	while (currentSize > 0) {
		cout << data[1] << ", ";
		data[1] = data[currentSize];
		data[currentSize] = 0;
		currentSize--;
		sink(1); // make sure not broken
	}
	return;
}
void Heap::print(int index) { // print using tabs visually
	if (left(index) <= currentSize) { // recursive left
		print(left(index));
	}

	int tabs = log10(index) / log10(2); // how many tabs
	for (int i = 0; i < tabs; i++) {
		cout << "    ";
	}
	cout << data[index] << endl;

	if (right(index) <= currentSize) { // recursive right
		print(right(index));
	}

	return;
}
void Heap::sink(int index) { // sink down
	if (data[left(index)] == 0 || left(index) > currentSize) { // out of bounds
		return;
	} 
	if (data[index] < data[left(index)]) { // left greater then
		swap(index, left(index));
		sink(index);
		sink(left(index));
		return;
	}
	if (data[right(index)] == 0 || right(index) > currentSize) { // out of bounds
		return;
	}
	if (data[index] < data[right(index)]) { //right greater then
		swap(index, right(index));
		sink(index);
		sink(right(index));
		return;
	}
	return;
}
void Heap::swim(int index) { // sort up
	if (index == 1) { // root
		return;
	}
	if (data[parent(index)] < data[index]) { // if parent greater then swap
		swap(parent(index), index);
		swim(parent(index));
	}
	return;
}
