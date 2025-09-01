#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int stairNum;
	cin >> stairNum;
	vector<int> stairs(stairNum);
	vector<int> dp(stairNum);

	for (int i = 0; i < stairNum; i++) {
		cin >> stairs[i];
	}
	
	dp[0] = stairs[0];
	dp[1] = dp[0] + stairs[1];
	dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < stairNum; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << dp[stairNum - 1]<<'\n';
}