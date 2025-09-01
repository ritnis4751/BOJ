#include<iostream>
#include<vector>
using namespace std;

int makeInt(const vector<int>& number) {
	int digit = 1;
	for (int i = 0; i < number.size() - 1; i++) {
		digit *= 10;
	}
	int ans = 0;
	for (int i = 0; i < number.size(); i++) {
		ans += number[i] * digit;
		digit /= 10;
	}
	return ans;
}

int main() {
	string str;
	cin >> str;

	int len = str.length();
	vector<int> nums;
	vector<char> operators;
	vector<int> tempNum;

	for (int i = 0; i < len; i++) {
		if('0' <= str[i] && str[i] <= '9') {
			tempNum.push_back(str[i]-'0');
		}
		else {
			int temp = makeInt(tempNum);
			nums.push_back(temp);
			tempNum.clear();
			operators.push_back(str[i]);
		}
	}nums.push_back(makeInt(tempNum));

	int index = 0;
	for (; index < operators.size(); index++) {
		if (operators[index] == '-') break;
	}
		
	int ans = 0;
	for (int i = 0; i <= index; i++) {
		ans += nums[i];
	}	
	for (int i = index + 1; i < nums.size(); i++) {
		ans -= nums[i];
	}
	cout << ans;
}