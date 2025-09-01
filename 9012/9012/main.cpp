#include<iostream>
#include<stack>
using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();

	for (int tsc = 0; tsc < t; tsc++) {
		char str[51];
		cin.getline(str, 51);
		stack<char> s;
		string ans = "YES";
		
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == '(')
				s.push(str[i]);
			else if (s.empty()) {
				ans = "NO";
				break;
			}
			else s.pop();
		}
		if (!s.empty()) ans = "NO";
		cout << ans << endl;
	}

}