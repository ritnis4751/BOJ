#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> dp(1001, 0);

int main() {
	int n;
	cin >> n;
	int ans = 0;

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[n] << '\n';
}