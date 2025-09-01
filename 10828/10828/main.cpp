#include<iostream>
using namespace std;

class Stack
{
public:
	Stack(int N) {
		arr = new int[N];
	};
	~Stack() {
		delete[] arr;
	};

	void push(int N) {
		arr[currentSize] = N;
		currentSize++;
	}

	int pop() {
		if (currentSize != 0) {
			currentSize--;
			return arr[currentSize];
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

	int top() {
		if (currentSize > 0) return arr[currentSize - 1];
		else return -1;
	}

private:
	int* arr;
	int currentSize = 0;
};

int main() {
	int N;
	cin >> N;
	Stack s = Stack(N);
	for(int i = 0; i < N; i ++){
		string command;
		cin >> command;

		if (command == "push") {
			int n;
			cin >> n;
			s.push(n);
		}
		else if (command == "pop")
			cout << s.pop() << endl;
		else if (command == "size")
			cout << s.size() << endl;
		else if (command == "empty")
			cout << s.empty() << endl;
		else if (command == "top")
			cout << s.top() << endl;
	}


}