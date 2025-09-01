#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	unordered_map<string, string> passwords;
	while (N--) {
		string site;
		string password;
		cin >> site >> password;
		passwords.insert({ site , password });
	}

	while (M--) {
		string site;
		cin >> site;
		cout << passwords[site] << '\n';
	}
}