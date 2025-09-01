#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;
	bool* arr = new bool[n + 1];
	// 0 ~ n
	for (int i = 0; i < n + 1; i++) {
		arr[i] = true;
	}
	arr[0] = false;
	arr[1] = false;

	// 제곱근까지만 검사하면 됨
	for (int i = 2; i * i <= n; i++) {
		if (arr[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				arr[j] = false;
			}
		}
	}

	for (int i = m; i < n + 1; i++) {
		if (arr[i]) cout << i << '\n';
	}

	delete[] arr;
}