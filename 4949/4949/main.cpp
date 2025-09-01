#include<iostream>
#include<stack>
using namespace std;

int main() {
	while (true) {

		char* str = new char[101];
		cin.getline(str, 101);
		stack<char> s;
		string ans = "yes";

		if (str[0] == '.')
			break;

		int i = 0;
		// °ýÈ£¸¸ ÀÔ·Â¹ÞÀ¸¸é µÊ
		for(int i = 0; str[i] != '.'; i ++){
			if (str[i] == '('){
				s.push(str[i]);
				continue;
			}else if (str[i] == '{'){
				s.push(str[i]);
				continue;
			}else if (str[i] == '['){
				s.push(str[i]);
				continue;
			}

			// each cases
			if (str[i] == ')') {
				// unballanced
				if (s.empty() || s.top()!= '(') {
					ans = "no";
					break;
				}// ballanced
				else {
					s.pop();
					continue;
				}
			}
			else if (str[i] == '}') {
				// unballanced
				if (s.empty() || s.top() != '{') {
					ans = "no";
					break;
				}// ballanced
				else {
					s.pop();
					continue;
				}
			}
			else if (str[i] == ']') {
				// unballanced
				if (s.empty() || s.top() != '[') {
					ans = "no";
					break;
				}// ballanced
				else {
					s.pop();
					continue;
				}
			}//end if
		}//end for
		if (!s.empty()) ans = "no";

		cout << ans << endl;
		delete[] str;
	}//end while
}