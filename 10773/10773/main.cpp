#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> s;
	int t;
	cin >> t;
	for (int tsc = 0; tsc < t; tsc++) {
		int n;
		cin >> n;
		if (n == 0) s.pop();
		else s.push(n);
	}
	int ans = 0;
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans << endl;
}