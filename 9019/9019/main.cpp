#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//start D
int D(int n) {
	int ans = (n * 2) % 10000;
	return ans;
}// end D

//start S
int S(int n) {
	return (n == 0) ? 9999 : n - 1;	
}// end S

//start L
int L(int n) {
	int ans;
	int d0 = n / 1000;
	ans = (n % 1000) * 10 + d0;
	return ans;
}// end L

// start R
int R(const int n) {
	int ans;
	int d3 = n % 10;
	ans = n / 10;
	ans += d3 * 1000;
	return ans;
}// end R


int main() {
	int T;
	cin >> T;
	while (T--) {
		
		int A, B;
		cin >> A >> B;

		char nextCommand[4] = { 'D', 'S', 'L', 'R' };
		vector<string> command(10000, "");

		vector<bool> visited(10000, false);
		queue<int> q;
		q.push(A);
		command[A] = "";
		visited[A] = true;
		while (!q.empty()) {
			int n = q.front();
			q.pop();

			if (n == B) {
				cout << command[n] << endl;
				break;
			}

			int next[4] = { D(n), S(n), L(n), R(n) };

			for (int i = 0; i < 4; i++) {
				if (!visited[next[i]]) {
					visited[next[i]] = true;
					q.push(next[i]);
					command[next[i]] = command[n] + nextCommand[i];
				}
			}


		}
	}
}