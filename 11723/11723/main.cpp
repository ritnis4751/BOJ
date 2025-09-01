#include<iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int	M;
	cin >> M;

	int S = 0;

	// do operator
	string operate;
	int x;
	while(M--) {
		cin >> operate;

		// case1: add
		if (operate == "add") {
			cin >> x;
			S |= (1 << (x - 1));
		}
		// case2: remove
		else if (operate == "remove") {
			cin >> x;
			S &= ~(1 << (x - 1));
		}// case3: check
		else if (operate == "check") {
			cin >> x;
			cout << ((S & (1 << (x - 1))) ? 1 : 0) << '\n';
		}// case4: toggle
		else if (operate == "toggle") {
			cin >> x;
			S ^= (1 << (x - 1));
		}
		// case5: all
		else if (operate == "all") {
			S = (1 << 20) - 1;
		}
		// case6: empty
		else if (operate == "empty") {
			S = 0;
		}
	}
}