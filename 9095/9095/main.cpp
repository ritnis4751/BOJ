#include<iostream>
#include<vector>
using namespace std;

vector<int> dp(11, 0);

int counter(int n) {
	//already has dp[n]
	if (dp[n] > 0) return dp[n];


	int result = 0;
	if (n >= 3) {
		result = counter(n - 3) + counter(n - 2) + counter(n - 1);
		dp[n] = result;
		return result;
	}
	else return dp[n];
}

int main() {
	int T;
	cin >> T;
	vector<int> arr;

	int max = 0;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		if (n > max) max = n;
		arr.push_back(n);
	}
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	counter(max);
	for (int i = 0; i < arr.size(); i++) {
		cout << dp[arr[i]] << '\n';
	}
}