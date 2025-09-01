#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<unsigned long int, unsigned long int>> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;
	

	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		pair<unsigned long int, unsigned long int> temp = { end, start };
		arr.push_back(temp);
	}

	stable_sort(arr.begin(), arr.end());

	int before = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		int begin = arr[i].second;
		int end = arr[i].first;

		if (before <= begin) {
			before = end;
			cnt++;
		}
	}

	cout << cnt;
}