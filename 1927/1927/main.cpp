#include<iostream>
#include<set>
#include<queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	priority_queue<int, vector<int>, greater<int>> q;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (x != 0) q.push(x);
		else if (!q.empty()) {
			int ans;
			ans = q.top();
			q.pop();
			cout << ans << '\n';
		}
		else cout << '0' << '\n';
	}
}