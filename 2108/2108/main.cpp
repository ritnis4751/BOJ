#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

int main() {
	int N;
	cin >> N;

	// data
	vector<int> save;
	double average = 0;
	map<int, int> modeSave;

	//input
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		save.push_back(temp);
		average += temp;
	}
	//sorting
	sort(save.begin(), save.end());

	//answer
	int ans[4];

	// 1.get average
	average = average / N;
	ans[0] = round(average);

	// 2.get middle value
	ans[1] = save[save.size() / 2];

	// 3.get mode value
	for (int i = 0; i < N; i++) {
		++modeSave[save[i]];
	}

	int mostMode = 0;
	auto iter = modeSave.begin();
	map<int, int> answerMap;

	while (iter != modeSave.end()) {
		// find most mode value
		if (iter->second > mostMode) {
			mostMode = iter->second;
			answerMap.erase(answerMap.begin(), answerMap.end());
			answerMap.insert({ iter->first, iter->second });
		}// find another most mode value
		else if(iter -> second == mostMode){
			answerMap.insert({ iter->first, iter->second });
		}
		iter++;
	}

	if (answerMap.size() > 1) {
		iter = answerMap.begin();
		++iter;
		ans[2] = iter->first;
	}
	else ans[2] = answerMap.begin()->first;

	// 4.get range
	auto start = save.begin();
	auto end = save.end();
	--end;
	ans[3] = *end - *start;

	// print answer
	std::cout << ans[0] << "\n" << ans[1] << "\n" << ans[2] << "\n" << ans[3] << "\n";
}