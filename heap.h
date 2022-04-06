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
	void debug();
	int left(int index); // left
	int right(int index); // right
	int parent(int index); // parent
	void swap(int x, int y); // swap 2 indecies
	void addNum(int num); // add number
	void out(); // output table least to greatest
	void print(int index);// print entire tree visually
	void sink(int index); //sort down
	void swim(int index); // sort up
};

