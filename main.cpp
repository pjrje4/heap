#include <iostream>
#include "heap.h"
using namespace std;

int main() {
	Heap* h = new Heap(5);
	h->debug();
	h->addNum(5);
	h->debug();
	h->addNum(3);
	h->debug();
	h->addNum(2);
	h->debug();
	h->addNum(10);
	h->debug();
	h->addNum(12);
	h->debug();
	h->out();
	cout << "outed" << endl;
	return 0;
}
