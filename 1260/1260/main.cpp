#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<stack>
using namespace std;

void dfs(const vector<set<int>>& graph, int start) {
	vector<bool> visited(graph.size() + 1, false);
	vector<int> ans;
	visited.push_back(start);
	stack<int> s;

	int node = start;
	s.push(start);

	while (!s.empty()) {
		node = s.top();
		s.pop();

		if (visited[node]) continue;

		ans.push_back(node);
		visited[node] = true;

		auto iter = graph[node].rbegin();
		while (iter != graph[node].rend()) {
			s.push(*iter);
			iter++;
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

void bfs(const vector<set<int>> graph, int start) {
	queue<int> q;
	vector<bool> visited(graph.size(), false);
	vector<int> ans;

	q.push(start);
	while(!q.empty()){
		int node = q.front();
		q.pop();

		if (visited[node]) continue;

		ans.push_back(node);
		visited[node] = true;

		auto iter = graph[node].begin();
		while(iter != graph[node].end()) {
			q.push(*iter);
			iter++;
		}

	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
}

int main() {
	int N, M, start;
	cin >> N >> M >> start;
	
	vector<set<int>> graph(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].insert(b);
		graph[b].insert(a);
	}

	dfs(graph, start);
	bfs(graph, start);


}