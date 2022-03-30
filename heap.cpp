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
	sort(i);
	return;
}
void Heap::out() {
	while (currentSize > 0) {
		cout << data[1] << ", ";
		data[1] = data[currentSize + 1];
		data[currentSize + 1] = NULL;
		sort(1);
	return;
}
void Heap::print() {
	return;
}
void Heap::sort(int index) {
	if (data[parent(index)] < data[index]) {
		swap(parent(index), index);
		sort(parent(index));
	}
	else if (data[index] < data[left(index)]) {
		swap(index, left(index));
		sort(left(index));
	}
	else if (data[index] < data[right(index)]) {
		swap(index, right(index));
		sort(right(index));
	}
	return;
}
int Heap::left(int index) {
	return index*2;
}
int Heap::right(int index) {
	return index*2+1;
}
int Heap::parent(int index) {
	return (index-1)/2;
}
void Heap::swap(int x, int y) {
	int temp = data[x];
	data[x] = data[y];
	data[y] = temp;
}
