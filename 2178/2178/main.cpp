#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;


int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> maze(N,vector<int>(M));
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++) {
			maze[i][j] = str[j] - '0';
		}
	}

	vector<vector<int>> dist(N, vector<int>(M, 0));

	queue<pair<int, int>> q;
	q.push({0, 0});
	int dir[4][2] = { {0,1}, {0, -1}, {1, 0},{-1,0} };
	dist[0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && maze[ny][nx] == 1 && dist[ny][nx] == 0) {
				q.push({ nx, ny });
				dist[ny][nx] = dist[y][x] + 1;
			}
		}
	}

	cout << dist[N - 1][M - 1];
}