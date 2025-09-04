#include<iostream>
#include<vector>
using namespace std;

int N, M;
int tetromino[19][4][2] = {
	// ---- 1. I자 ----
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}}, // 가로
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}}, // 세로

	// ---- 2. O자 ----
	{{0, 0}, {1, 0}, {0, -1}, {1, -1} }, // 정사각형

	// ---- 3. L자 (8가지 변형) ----
	{{0, 0}, {0, -1}, {0, -2}, {1, -2}},
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	{{0, 0}, {1, 0}, {1, -1}, {1, -2}},
	{{0, 0}, {1, 0}, {2, 0}, {0, -1}},
	{{0, 0}, {0, -1}, {0, -2}, {-1, -2}},
	{{0, 0}, {1, 0}, {2, 0}, {2, -1}},
	{{0, 0}, {1, 0}, {0, -1}, {0, -2}},
	{{0, 0}, {0, -1}, {1, -1}, {2, -1}},

	// ---- 4. S자 (4가지 변형) ----
	{{0, 0}, {0, -1}, {1, -1}, {1, -2} },
	{{0, 0}, {1, 0}, {-1, -1}, {0, -1} },
	{{0, 0}, {0, -1}, {-1, -1}, {-1, -2} },
	{{0, 0}, {1, 0}, {1, -1}, {2, -1} },

	// ---- 5. T자 (4가지 변형) ----
	{{0, 0}, {-1, 0}, {1, 0}, {0, -1}},
	{{0, 0}, {0, 1},{1, 0}, {0, -1} },
	{{0, 0}, {-1, 0}, {0, 1},{1, 0} },
	{{0, 0}, {0, 1}, {0, -1}, {-1, 0} }
};

int checkSum(int x, int y, vector<vector<int>>& board) {
	int ans = 0;
	for (int i = 0; i < 19; i++) {
		int temp = 0;
		bool isIn = true;
		for (int j = 0; j < 4; j++) {
			int nx = x + tetromino[i][j][0];
			int ny = y + tetromino[i][j][1];
			if (0 <= nx && nx < M && 0 <= ny && ny < N) temp += board[ny][nx];
			else {
				isIn = false;
				break;
			}
		}
		if (isIn) ans = (temp > ans) ? temp : ans;
	}

	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	// make board
	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
		}
	}// end make board
	
	// start check sum
	int ans = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int temp = checkSum(x, y, board);
			ans = (temp > ans) ? temp : ans;
		}
	}
	cout << ans;
	// end check sum
}