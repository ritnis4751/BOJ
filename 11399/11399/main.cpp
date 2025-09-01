#include<iostream>
#include<set>
using namespace std;

int main() {
	int N;
	cin >> N;
	multiset<int> line;

	for(int i = 0; i < N; i++) {
		int time;
		cin >> time;
		line.insert(time);
	}

	int ans = 0;
	int temp = 0;

	auto iter = line.begin();

	while(iter != line.end()) {
		temp += *iter;
		ans += temp;
		iter++;
	}
	cout << ans;


}