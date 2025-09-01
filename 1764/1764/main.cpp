#include<unordered_set>
#include<set>;
#include<iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	unordered_set<string> cantHearList;
	while (M--) {
		string name;
		cin >> name;
		cantHearList.insert(name);
	}

	set<string> cantHearSeeList;
	while (N--) {
		string name;
		cin >> name;
		if (cantHearList.find(name) != cantHearList.end()){
			cantHearSeeList.insert(name);
		}
	}
	
	auto iter = cantHearSeeList.begin();
	cout << cantHearSeeList.size() << endl;
	while (iter != cantHearSeeList.end()) {
		cout << *iter << '\n';
		iter++;
	}



}