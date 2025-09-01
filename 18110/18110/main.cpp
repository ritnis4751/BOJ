#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int k = round((float)n * 0.15f);
	double div = (n - 2 * k);
	int sum = 0;

	for (int i = k; i < n - k; i++) {
		sum += arr[i];
	}

	int ans = round((double)sum / (double)(n - 2* k));

	if (n == 0) cout << '0';
	else cout << ans;

}