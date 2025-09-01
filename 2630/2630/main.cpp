#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> paper;

int cuttingWhite(int left, int right, int up, int down) {
	if (left == right && up == down) {
		if (paper[up][left] == 1) return 0;
		else return 1;
	}

	bool check = true;
	for (int i = up; i <= down; i++) {
		for (int j = left; j <= right; j++) {
			if (paper[i][j] == 1) {
				check = false;
				break;
			}
		}
	}

	if (check) {
		return 1;
	}
	else {
		int midX = (left + right) / 2;
		int midY = (up + down) / 2;
		return cuttingWhite(left, midX, up, midY)				//�»� 
			+ cuttingWhite(midX + 1, right, up, midY)			//���
			+ cuttingWhite(left, midX, midY + 1, down)			//����
			+ cuttingWhite(midX + 1, right, midY + 1, down);	//����
	}
}
int cuttingBlue(int left, int right, int up, int down) {

	if (left == right && up == down) {
		if (paper[up][left] == 0) return 0;
		else return 1;
	}

	bool check = true;
	for (int i = up; i <= down; i++) {
		for (int j = left; j <= right; j++) {
			if (paper[i][j] == 0) {
				check = false;
				break;
			}
		}
	}

	if (check) {
		return 1;
	}

	else {
		int midX = (left + right) / 2;
		int midY = (up + down) / 2;
		return cuttingBlue(left, midX, up, midY)			//�»� 
			+ cuttingBlue(midX  + 1, right, up, midY)		//���
			+ cuttingBlue(left, midX, midY + 1, down)		//����
			+ cuttingBlue(midX + 1, right, midY + 1, down);	//����
	}

}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> temp(N);
		for (int j = 0; j < N; j++) {
			cin >> temp[j];
		}
		paper.push_back(temp);
	}
	int white = cuttingWhite(0, N - 1, 0, N - 1);
	int blue = cuttingBlue(0, N - 1, 0, N - 1);
	cout << white << '\n';
	cout << blue << '\n';
}