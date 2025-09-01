#include<iostream>
#include<deque>
#include<string>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int tsc = 0; tsc < T; tsc++) {
		string function;
		cin >> function;

		// size of array N
		int N;
		cin >> N;
		deque<int> arr;

		string p;
		cin >> p;

		string num;
		for (char c : p) {

			if (isdigit(c)) {
				num += c;
			}
			else {
				if (!num.empty()) {
					arr.push_back(stoi(num)); 
					num.clear();
				}
			}
		}

		bool isReverse = false;
		bool error = false;
		for (int i = 0; i < function.size(); i++) {
			if (function[i] == 'R') {
				isReverse = !isReverse;
			}
			else {
				if (arr.empty()) {
					cout << "error\n";
					error = true;
					break;
				}else if (isReverse) arr.pop_back();
				else arr.pop_front();
			}
		}

		if (!error) {
			if (arr.empty()) {
				cout << "[]\n";
			}
			else if(!isReverse) {
				auto iter = arr.begin();
				cout << '[' << *iter;
				iter++;
				while (iter != arr.end()) {
					cout << ',' << *iter;
					iter++;
				}
				cout << "]\n";
			}
			else if (isReverse) {
				auto iter = arr.rbegin();
				cout << '[' << *iter;
				iter++;
				while (iter != arr.rend()) {
					cout << ',' << *iter;
					iter++;
				}
				cout << "]\n";
			}
		}
	}
}