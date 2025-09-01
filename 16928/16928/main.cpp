#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> board(101, 0);
	vector<int> dist(101, -1);

	for (int i = 0; i < M + N; i++) {
		int start, end;
		cin >> start >> end;
		board[start] = end;
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 1; i < 7; i++) {
			int next = current + i;
			if (next > 100) break;

			// 사다리 또는 뱀
			if (board[next] != 0) {
				next = board[next];
			}

			// 방문한 적이 없을 때
			if (dist[next] == -1) {
				q.push(next);
				dist[next] = dist[current] + 1;
			}
		}
	}
	cout << dist[100] << endl;
	
}