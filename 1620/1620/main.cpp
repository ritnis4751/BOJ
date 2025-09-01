#include<map>
#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M, N;
	cin >> M >> N;

	// {"name", number}
	unordered_map<string, int> guideOnName;

	// {number, "name"}
	unordered_map<int, string> guideOnKey;

	// input pocketmons
	for (int i = 1; i <= M; i++) {
		string name;
		cin >> name;
		guideOnName.insert({ name, i });
		guideOnKey.insert({ i, name });
	}

	// print ans
	string ans = "";
	while (N--) {
		string Q;
		cin >> Q;
		if ('0' <= Q[0] && Q[0] <= '9') {
			int num = stoi(Q);
			cout << guideOnKey[num] << '\n';
		}
		else {
			cout << guideOnName[Q] << '\n';
		}
	}
}