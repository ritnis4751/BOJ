#include<iostream>
using namespace std;

int main() {
	int N;
	int K;
	cin >> N >> K;

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int index = N - 1;
	int ans = 0;

	while (K > 0) {
		int result = K / arr[index];
		ans += result;
		K -= result * arr[index];

		index--;
	}
	cout << ans;
	delete[] arr;
}