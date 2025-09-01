#include<iostream>
#include<string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	string Sn = "I";

	string str;
	cin >> str;

	int ans = 0;
	int cnt = 0;
	for (int i = 1; i < M - 1; i++) {
		if (str[i - 1] == 'I' && str[i] == 'O' && str[i + 1] == 'I') {
			cnt++;
			if (cnt == N) {
				ans++;
				cnt--;
			}
			i++;
		}
		else {
			cnt = 0;
		}

	}
	cout << ans;
}