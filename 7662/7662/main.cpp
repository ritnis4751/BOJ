#include<iostream>
#include<set>
using namespace std;

int main() {
	iostream::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	cin >> T;

	for (int tsc = 0; tsc < T; tsc++) {
		int k;
		cin >> k;

		multiset<int> q;
		for (int i = 0; i < k; i++) {
			char oper;
			cin >> oper;

			int n;
			cin >> n;
			if (oper == 'I') {
				q.insert(n);
			}
			else if(!q.empty()){
				if (n == 1) {
					q.erase(prev(q.end()));
				}
				else {
					q.erase(q.begin());
				}
			}

		}

		if (!q.empty()) {
			cout << *prev(q.end()) << ' ' << *q.begin()  << '\n';
		}
		else cout << "EMPTY\n";
	}
}
