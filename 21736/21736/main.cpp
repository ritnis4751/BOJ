#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<char>> campus(N, vector<char>(M));


	pair<int, int> start;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < M; j++){
			campus[i][j] = str[j];
			if (str[j] == 'I') {
				start = { j, i };
			}
		}
	}

	queue<pair<int, int>> q;
	vector<vector<int>> dir(4, vector<int>(2));
	dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	int ans = 0;
	q.push(start);
	campus[start.second][start.first] = 'X';
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if (0 <= ny && ny < N && 0 <= nx && nx < M) {
				char point = campus[ny][nx];
				if (point == 'P') {
					++ans;
					campus[ny][nx] = 'X';
					q.push({ nx, ny });
				}
				else if (point == 'O') {
					campus[ny][nx] = 'X';
					q.push({ nx, ny });
				}
			}
		}
	}
	if (ans)cout << ans;
	else cout << "TT";

}