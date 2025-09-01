#include<iostream>
#include<queue>
using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b)) return a > b; 
        return abs(a) > abs(b);             
    }
};

int main() {
	priority_queue<int,vector<int>, Compare> q;

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (q.empty())cout << "0\n";
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else q.push(x);
    }
}
