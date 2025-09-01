#include<iostream>
#include<map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	map<int, int> counter;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		counter[num]++;
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int query;
		cin >> query;
		cout << counter[query] << ' ';
	}
	return 0;
}