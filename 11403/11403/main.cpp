#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void bfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int start) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i];
			if (!visited[start][next]) {
				visited[start][next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> graph(N);
	for (int i = 0; i < N; i++) {
		int x;
		for (int j = 0; j < N; j++) {
			cin >> x;
			if (x) {
				graph[i].push_back(j);
			}
		}
	}

	vector<vector<bool>> visited(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		bfs(graph, visited, i);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
}