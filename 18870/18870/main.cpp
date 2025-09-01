#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N; 

	vector<int> arr(N);
	unordered_map<int, int> map;
	set<int> s;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		s.insert(arr[i]);
	}

	auto iter = s.begin();
	int cnt = 0;
	while (iter != s.end()) {
		map.insert({ *iter, cnt });
		cnt++;
		iter++;
	}

	for (int i = 0; i < N; i++) {
		cout << map[arr[i]] << ' ';
	}
}