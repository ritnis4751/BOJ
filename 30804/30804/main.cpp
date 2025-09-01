#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> fruitCount; // ���� ������ ����
    int left = 0, ans = 0;

    for (int right = 0; right < N; right++) {
        fruitCount[arr[right]]++;

        // ���� ������ 2�� �ʰ��ϸ� ���� ������ �̵�
        while (fruitCount.size() > 2) {
            fruitCount[arr[left]]--;
            if (fruitCount[arr[left]] == 0) {
                fruitCount.erase(arr[left]);
            }
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans;
    delete[] arr;
    return 0;
}
