#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> farm;
vector<vector<bool>> visited;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	pair<int, int> start;
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		vector<int> temp;

		for (int j = 0; j < M; j++) {
			int tomato;
			cin >> tomato;

			if (tomato == 1) {
				start.first = j;
				start.second = i;
				q.push(start);
			}
			temp.push_back(tomato);
		}
		farm.push_back(temp);
	}
	
	while (!q.empty()) {
		pair<int, int> coor = q.front();
		int x = coor.first;
		int y = coor.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (0 <= nx && nx < M && 0 <= ny && ny < N && farm[ny][nx] == 0) {
				farm[ny][nx] = farm[y][x] + 1;
				q.push({ nx, ny });
			}
		}
	}
	int days = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (farm[i][j] > days) days = farm[i][j];
			if (farm[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << days - 1;

}