#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int counting(int n, int cnt) {
	vector<int> dp;
	while (1) {

	}
}

int main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1, 0);
	int root = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n] << '\n';
}
