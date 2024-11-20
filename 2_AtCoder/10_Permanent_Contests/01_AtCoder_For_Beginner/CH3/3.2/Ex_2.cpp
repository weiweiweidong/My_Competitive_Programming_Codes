// https://atcoder.jp/contests/abc206/tasks/abc206_b

#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;
    long long res = 0;
    for (int i = 1; i <= N; i++) {
        res += i;
        if (res >= N) {
            cout << i << endl;
            return 0;
        }
    }
}
