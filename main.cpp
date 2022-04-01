#include <iostream>

using namespace std;

int main() {
	Heap* h = new Heap(5);
	h->addNum(5);
	h->addNum(3);
	h->addNum(2);
	h->addNum(10);
	h->addNum(12);
	h->out();
}
