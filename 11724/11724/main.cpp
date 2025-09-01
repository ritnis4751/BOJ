#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

void bfs(const vector<set<int>>& nodes, set<int>& unvisited) {
	int start = *unvisited.begin();
	queue<int> q;
	q.push(start);
	unvisited.erase(start);

	while (!q.empty()) {
		int currentNode = q.front();
		q.pop();
		auto iter = nodes[currentNode].begin();

		while (iter != nodes[currentNode].end()) {
			if (unvisited.find(*iter) != unvisited.end()) {
				q.push(*iter);
				unvisited.erase(*iter);
			}
			iter++;
		}
	}
}

int main() {
	int N;
	int M;
	cin >> N >> M;

	vector<set<int>> nodes(N + 1);
	set<int> unvisited;

	for (int i = 1; i <= N; i++) {
		unvisited.insert(i);
	}
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a].insert(b);
		nodes[b].insert(a);
	}
	int ans = 0;

	while(!unvisited.empty()) {
		bfs(nodes, unvisited);
		ans++;
	}
	cout << ans << '\n';
}