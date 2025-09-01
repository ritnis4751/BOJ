#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct coordinate {
	int h, y, x;
};

int main() {
	int M, N, H;
	cin >> M >> N >> H;
	queue<coordinate> q;

	// farm[h][y][x]
	vector<vector<vector<int>>> farm(H, vector<vector<int>>(N, vector<int>(M)));
	for (int h = 0; h < H; h++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> farm[h][y][x];
				if (farm[h][y][x] == 1) {
					q.push({ h, y, x });
				}
			}
		}
	}

	vector<coordinate> dir = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };

	while (!q.empty()) {
		int x, y, h;
		x = q.front().x;
		y = q.front().y;
		h = q.front().h;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nx, ny, nh;
			nx = x + dir[i].x;
			ny = y + dir[i].y;
			nh = h + dir[i].h;

			if (0 <= nx && nx < M && 0 <= ny && ny < N && 0 <= nh && nh < H && farm[nh][ny][nx] == 0) {
				q.push({ nh, ny, nx });
				farm[nh][ny][nx] = farm[h][y][x] + 1;
			}
		}
	}

	int day = -1;
	bool clear = true;
	for (int h = 0; h < H; h++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (farm[h][y][x] == 0) {
					cout << -1;
					return 0;
				}
				else if (farm[h][y][x] > day) day = farm[h][y][x];
			}
		}
	}

	cout << day - 1;
}