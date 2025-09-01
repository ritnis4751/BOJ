#include<iostream>
using namespace std;

class Queue
{
public:
	Queue(int N);
	~Queue();

	void push(int N) {
		arr[currentSize] = N;
		currentSize++;
	}

	int pop() {
		if (currentSize != 0) {
			int n = arr[0];
			for (int i = 0; i < currentSize - 1; i++){
				arr[i] = arr[i + 1];
			}
			currentSize--;
			return n;
		}
		else return -1;
	}

	int size() {
		return currentSize;
	}

	int empty() {
		if (currentSize <= 0) return 1;
		else return 0;
	}

	int front() {
		if (currentSize > 0) return arr[0];
		else return -1;
	}
	
	int back() {
		if (currentSize > 0) return arr[currentSize - 1];
		else return -1;
	}
private:
	int* arr;
	int currentSize = 0;
};

Queue::Queue(int N)
{
	arr = new int[N];
}

Queue::~Queue()
{
	delete[] arr;
}


int main() {
	int N;
	cin >> N;
	Queue q = Queue(N);

	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;

		if (command == "push") {
			int n;
			cin >> n;
			q.push(n);
		}
		else if (command == "pop")
			cout << q.pop() << endl;
		else if (command == "size")
			cout << q.size() << endl;
		else if (command == "empty")
			cout << q.empty() << endl;
		else if (command == "front")
			cout << q.front() << endl;
		else if (command == "back")
			cout << q.back() << endl;
	}
}