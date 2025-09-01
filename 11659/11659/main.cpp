#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	int M;
	cin >> N >> M;

	int arr[100001] = { 0, };
	unsigned long dp[100001] = { 0, };
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int k = 0; k < M; k++) {
		int i;
		int j;
		cin >> i >> j;

		cout << dp[j] - dp[i - 1] << '\n';
	}
	
}