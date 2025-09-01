#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	vector<char> ans;

	int num;
	cin >> num;

	stack<int> s;
	int currentNum = 1;
	for (int i = 0; i < num; i++) {
		int target;
		cin >> target;

		// 1: target <= currentNum; push
		while (currentNum <= target) {
			s.push(currentNum);
			currentNum++;
			ans.push_back('+');
		}
		// 2: target == currentNum; pop
		if (s.top() == target) {
			s.pop();
			ans.push_back('-');
		}
		else {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}