#if 0
Justin Iness
3/17/2022
C++ Programming
Heap
#endif

class Heap {
private:
	Heap(); // Constructor
	~Heap(); // Destructor
	int data[101];
public:
	// Input
	void addNum(int num);
	// Delete
	void delNum(int num);
	// Print Entire Table
	void print();
};

