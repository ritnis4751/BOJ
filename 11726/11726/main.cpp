#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> dp(1001, 0);

int counting(int n) {
	if (dp[n] != 0) return dp[n];

	dp[n] = counting(n - 1) + counting(n - 2) * 2;
	return dp[n];
	
}

int main() {
	int n;
	cin >> n;
	int ans = 0;

	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n] << '\n';
}