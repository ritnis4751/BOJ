#include<iostream>
using namespace std;

int cutting(unsigned int arr[], int k,int len) {
	if (len == 0) return 0;
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += arr[i] / len;
	}
	return cnt;
}


int main() {
	// get input
	int k;
	int n;
	cin >> k >> n;

	// get lan line's legnth
	unsigned int* arr = new unsigned int[k];
	unsigned int up = 0;
	unsigned int down = 1;
	
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		// get shortest len
		if (up < arr[i]) up = arr[i];
	}

	int result = 0;
	while (down <= up) {
		unsigned int mid = down + (up - down) / 2;
		// increase mid
		if (cutting(arr, k, mid) >= n) {
			result = mid;
			down = mid + 1;
		}
		else {
			up = mid - 1;
		}
	}

	cout << result << endl;


	delete[] arr;
}