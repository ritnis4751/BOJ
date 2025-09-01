#include<iostream>
using namespace std;


int main() {
    int f0[41];
    int f1[41];

    f0[0] = 1;
    f0[1] = 0;
    f1[0] = 0;
    f1[1] = 1;

    for (int i = 2; i < 41; i++) {
        f0[i] = f0[i - 2] + f0[i - 1];
        f1[i] = f1[i - 2] + f1[i - 1];
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << f0[n] << ' ' << f1[n] << '\n';
    }
}