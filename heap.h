#if 0
Justin Iness
3/17/2022
C++ Programming
Heap
#endif

class Heap {
private:
	int *data;
	int maxSize;
	int currentSize;
public:
	Heap(int size); // Constructor
	~Heap(); // Destructor
	// Input
	void addNum(int num);
	// Delete
	void delNum(int num);
	// Print Entire Table
	void print();
};

