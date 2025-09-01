#include<iostream>
#include<vector>
using namespace std;

unsigned long int cutting(const vector<int>& trees, int h) {
    unsigned long int ans = 0;
    for (int i = 0; i < trees.size(); i++) {
        if(trees[i] > h) ans += trees[i] - h;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    unsigned long int M;
    cin >> N >> M;
    vector<int> trees(N);

    int higher = 0;
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
        if (higher < trees[i]) higher = trees[i];
    }
    
    int H = higher / 2;
    int lower = 0;
    int ans = 0;
    while (lower <= higher) {
        H = lower + (higher - lower) / 2;
        unsigned long int cut = cutting(trees, H);
        if(cut >= M) {
            ans = H;
            lower = H + 1;
        }
        else {
            higher = H - 1;
        }
    }
    cout << ans << endl;
}