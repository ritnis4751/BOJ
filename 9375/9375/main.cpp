#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		unordered_map<string, set<string>> wears;

		for (int j = 0; j < n; j++) {
			string kind;
			string name;
			cin >> kind >> name;
			wears[name].insert(kind);
		}

		auto iter = wears.begin();
		int ans = 1;
		while (iter != wears.end()) {
			ans *= iter->second.size() + 1;
			iter++;
		}
		ans--;
		cout << ans << '\n';
	}
}