// https://atcoder.jp/contests/abc162/tasks/abc162_b

#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;
    long long res = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 3 && i % 5)
            res += i;
    }
    cout << res << endl;
}
