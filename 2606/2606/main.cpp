#include<iostream>
#include<map>
#include<set>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	map<int, set<int>> computers;
	set<int> virus;
	virus.insert(1);

	int M;
	cin >> M;
	// get networks
	for (int i = 0; i < M; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		computers[c1].insert(c2);
		computers[c2].insert(c1);
	}

	// bfs
	queue<int> q;
	q.push(1);
	vector<bool> isvisit(N + 1);
	isvisit[1] = true;

	while (!q.empty()) {
		int current = q.front();
		auto iter = computers[current].begin();

		while (iter != computers[current].end()) {
			if (!isvisit[*iter]) { 
				q.push(*iter); 
				virus.insert(*iter);
				isvisit[*iter] = true;
			}
			iter++;
		}
		q.pop();
	}
	cout << virus.size() - 1 << '\n';

}