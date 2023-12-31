// https://atcoder.jp/contests/abc090/submissions/me

#include <iostream>
#include <vector>
using namespace std;

int A, B;

// 返回x的回文数
int palin(int x) {
    int t = 0;
    while (x) {
        t = t * 10 + x % 10;
        x /= 10;
    }
    return t;
}

int main() {
    cin >> A >> B;

    int cnt = 0;
    for (int i = A; i <= B; i++) {
        if (i == palin(i))
            cnt++;
    }
    cout << cnt;
}
