#include<iostream>
using namespace std;

int main() {
	string s;
	cin >> s;

	int sum = 0;
	int heaviness;

	// ISBN 확인
	for (int i = 0; i < 12; ++i) {
		// 손상되지 않음
		if (s[i] != '*') {
			if (i % 2 == 0) {
				sum += s[i] - '0';
			}
			else sum += (s[i] - '0') * 3;
		}
		else { //손상됨
			if (i % 2 == 0) heaviness = 1;
			else heaviness = 3;
		}
	}
	sum += s[12] - '0';

	for (int i = 0; i < 10; i++) {
		if ((sum + i * heaviness) % 10 == 0) {
			cout << i;
			break;
		}
	}
}