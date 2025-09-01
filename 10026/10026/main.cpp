#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int normalBFS(vector<string> area) {
	int ans = 0;
	for (int i = 0; i < area.size(); i++) {
		for (int j = 0; j < area[0].size(); j++) {
			// find start point
			if (area[i][j] != 'X') {
				char color = area[i][j];
				area[i][j] = 'X';

				// start bfs
				queue<pair<int, int>> q;
				q.push({ j, i });
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = x + dir[i][0];
						int ny = y + dir[i][1];

						if (0 <= nx && nx < N && 0 <= ny && ny < area.size() && area[ny][nx] == color) {
							q.push({ nx, ny });
							// check visited
							area[ny][nx] = 'X';
						}
					}
				}// end bfs

				++ans;
			}// if
		}// end for
	}// end for

	return ans;
}// end normalBFS

int blindedBFS(vector<string> area) {
	int ans = 0;
	for (int i = 0; i < area.size(); i++) {
		for (int j = 0; j < area[0].size(); j++) {

			// find start point
			if (area[i][j] != 'X') {
				char color = area[i][j];
				area[i][j] = 'X';

				// when color is green or red
				if (color == 'G' || color == 'R') {
					// start bfs
					queue<pair<int, int>> q;
					q.push({ j, i });

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int i = 0; i < 4; i++) {
							int nx = x + dir[i][0];
							int ny = y + dir[i][1];

							if (0 <= nx && nx < N && 0 <= ny && ny < area.size() && area[ny][nx] != 'B' && area[ny][nx] != 'X') {
								q.push({ nx, ny });
								// check visited
								area[ny][nx] = 'X';
							}
						}// end for
					}// end bfs
					++ans;
				}// when color is blue
				else {
					// start bfs
					queue<pair<int, int>> q;
					q.push({ j, i });

					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int i = 0; i < 4; i++) {
							int nx = x + dir[i][0];
							int ny = y + dir[i][1];

							if (0 <= nx && nx < N && 0 <= ny && ny < area.size() && area[ny][nx] == 'B') {
								q.push({ nx, ny });
								// check visited
								area[ny][nx] = 'X';
							}
						}
					}// end bfs
					++ans;
				}
			}// end if
		}// end for
	}// end for
	return ans;
}// end blindedBFS

int main() {
	cin >> N;
	
	vector<string> area(N);
	for (int i = 0; i < N; i++) {
		cin >> area[i];
	}

	cout << normalBFS(area) << ' ' << blindedBFS(area);
}