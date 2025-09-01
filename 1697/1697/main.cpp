#include <iostream>
#include <queue>
using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    int dist[100001] = { 0, };
    queue<int> q;

    cin >> N >> K;
    if (N == K) {
        cout << 0;
        return 0;
    }

    q.push(N);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int nx : { x - 1, x + 1, 2 * x }) {
            if (nx < 0 || nx > 100000) continue;
            if (nx == N || dist[nx] > 0) continue;
            if (nx == K) {
                cout << dist[x] + 1;
                return 0;
            }
            dist[nx] = dist[x] + 1;
            q.push(nx);
        }
    }
    throw;
}