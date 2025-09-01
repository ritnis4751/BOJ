#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int bfs(vector<vector<int>>& map, pair<int, int> start){
	int size = 1;
	queue<pair<int, int>> q;
	q.push(start);
	map[start.first][start.second] = 0;

	int dir[4][2] = { {1, 0}, {-1, 0}, {0 , 1}, {0, - 1} };
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (0 <= nx && nx < N && 0 <= ny && ny < N && map[nx][ny] == 1) {
				map[nx][ny] = 0;
				q.push({ nx, ny });
				++size;
			}
		}
	}
	return size;
}


int main() {
	cin >> N;
	vector<vector<int>> map(N,vector<int>(N));
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < N; j++) {
			map[i][j] = str[j] - '0';
		}
	}
	vector<int> size;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				size.push_back(bfs(map, { i, j }));
			}
		}
	}

	cout << size.size() << '\n';
	sort(size.begin(), size.end());
	for (int i = 0; i < size.size(); i++) {
		cout << size[i] << '\n';
	}
}