#include<iostream>
using namespace std;

int counting(unsigned long int n, unsigned long int r, unsigned long int c, int N, int count) {
	if (N < 1)return count;
	unsigned long int half = n / 2;

	if(r < half){
		// �»�
		if (c < half) {}
		// ���
		else {
			count += half * half;
			c = c - half;
		}
	}
	else {
		// ����
		if (c < half) {
			count += half * half * 2;
			r = r - half;
		}
		// ����
		else{
			count += half * half * 3;
			c = c - half;
			r = r - half;
		}
	}

	return counting(n / 2, r, c, N - 1, count);
}

int main() {
	int N;
	unsigned long int r, c;
	cin >> N >> r >> c;

	unsigned long int n = 1;
	for (int i = 0; i < N; i++) {
		n *= 2;
	}
	cout << counting(n, r, c, N, 0);
}