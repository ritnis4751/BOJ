#include<iostream>
#include<vector>
using namespace std;

int N, M;
int makeSite(const vector<vector<int>>& site, int blocks, int height) {
	int time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 블록 쌓기
			if(site[i][j] < height){				
				time += height - site[i][j];
				blocks -= height - site[i][j];
			}
			// 블록 캐기
			else {
				time += (site[i][j] - height) * 2;
				blocks += site[i][j] - height;
			}
		}
	}
	if (blocks < 0) return 64000001;
	return time;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int blocks;
	cin >> N >> M >> blocks;
	int max = -1;
	int min = 257;

	vector<vector<int>> site;

	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < M; j++) {
			int height;
			cin >> height;
			
			if (max < height) max = height;
			if (min > height) min = height;

			temp.push_back(height);
		}
		site.push_back(temp);
	}

	int ansTime = 64000001;
	int ansHeight = 0;
	for (int i = min; i <= max; i++) {
		int tempTime = makeSite(site, blocks, i);
		if (tempTime <= ansTime) {
			ansTime = tempTime;
			ansHeight = i;
		}
	}
	cout << ansTime << ' ' << ansHeight;
}