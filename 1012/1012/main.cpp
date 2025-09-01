#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> farm;
int X, Y, N;

bool finding(int x, int y) {
	if (farm[x][y] == 1) {
		farm[x][y] = 0;
		if (x - 1 >= 0) finding(x - 1, y);
		if (y - 1 >= 0) finding(x, y - 1);
		if (x + 1 < X) finding(x + 1, y);
		if (y + 1 < Y) finding(x, y + 1);

		return true;
	}
	else return false;
}


int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		cin >> X >> Y >> N;

		// input
		for (int i = 0; i < 50; i++) {
			vector<int> temp(50, 0);
			farm.push_back(temp);
		}

		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			farm[x][y] = 1;
		}
		
		// end input

		// finding
		int ans = 0;
		for (int x = 0; x < X; x++) {
			for (int y = 0; y < Y; y++) {
				if (finding(x, y)) ++ans;
			}
		}
		cout << ans << '\n';
		
	}
}