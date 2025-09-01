#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main() {
	int X;
	cin >> X;

	vector<int> dp(X + 1);
	dp[1] = 0;
	for (int i = 2; i <= X; i++) {
		// case 1
		if (i % 6 == 0) {
			dp[i] = min({ dp[i / 3], dp[i / 2], dp[i - 1] }) + 1;
		}// case 2
		else if (i % 3 == 0) {
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		}// case 3;
		else if (i % 2 == 0) {
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
		}// case 4
		else dp[i] = dp[i - 1] + 1;
	}
	cout << dp[X] << '\n';
}