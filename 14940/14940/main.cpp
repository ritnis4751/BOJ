#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int arr[1000][1000];
int dist[1000][1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                start.first = j;
                start.second = i;
                dist[i][j] = 0;
            }
            else if (arr[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }    
    
    queue<pair<int, int>> q;
    q.push(start);

    int next[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

    while (!q.empty()) {
        pair<int, int> coor = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = coor.first + next[i][0];
            int ny = coor.second + next[i][1];
            if (0 <= nx && nx < m && 0 <= ny && ny < n && dist[ny][nx] == -1 && arr[ny][nx] == 1) {
                q.push({ nx, ny });
                dist[ny][nx] = dist[coor.second][coor.first] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}