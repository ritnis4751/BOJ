#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> people(N+1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		people[a].push_back(b);
		people[b].push_back(a);
	}
	
	int ans = 0;
	int minDist = 1000000;

	for (int start = 1; start <= N; start++) {

		//bfs
		queue<int> q;
		vector<int> dist(N + 1, -1);
		dist[start] = 0;
		q.push(start);
		int allDist = 0;

		while (!q.empty()) {
			int current = q.front();
			q.pop();

			for (int j = 0; j < people[current].size(); j++) {
				int next = people[current][j];
				if (dist[next] == -1) {
					q.push(next);
					dist[next] = dist[current] + 1;
				}
			}
		}

		for (int j = 1; j < dist.size(); j++) {
			allDist += dist[j];
		}
		if (allDist < minDist) {
			minDist = allDist;
			ans = start;
		}
		

	}
	cout << ans;

}