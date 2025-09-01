#include<iostream>
using namespace std;
#include<queue>



int main() {
	int t;
	cin >> t;
	for (int tsc = 0; tsc < t; tsc++) {
		// input n
		int n;
		cin >> n;

		// arr[i][k]
		int arr[100][2] = { {0, 0} };
		// input target's number
		int target;
		cin >> target;

		// target's [i][1] is 1
		// others are 0
		arr[target][1] = 1;

		int priorities[10] = { 0 };

		// input priorities
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			arr[i][0] = temp;
			priorities[temp]++;
		}

		bool find = false;
		int i = 0;
		int currentPri = 9;
		// sellect first priorities
		while (priorities[currentPri] == 0) {
			currentPri--;
		}

		int cnt = 0;


		while (!find) {
			// printing
			if (arr[i][0] == currentPri) {
				// down priority num
				arr[i][0] = -1;
				priorities[currentPri]--;
				if (priorities[currentPri] == 0) currentPri--;
				cnt++;

				// target
				if (arr[i][1] == 1) {
					find = true;
				}
			}

			// print all current priority
			if (priorities[currentPri] == 0) currentPri--;

			// go to next index
			i++;
			// defence OOB
			if (i >= n) i = 0;
		}
		cout << cnt << endl;
	}
}