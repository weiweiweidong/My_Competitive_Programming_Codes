// Problem: https://atcoder.jp/contests/abc397/tasks/abc397_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL N;

void solve() {
    cin >> N;

    // 开始枚举 a
    for (LL a = 1; a * a <= N / a; a++) {
        // 判断是否存在 b
        if (N % a == 0) {
            LL b = N / a;

            // 判断 z 是否是个整数
            LL z = a * a - b;
            if (z % 3 == 0) {
                z /= 3;
                // 判断 y 是否存在
                if (a * a - 4 * z >= 0) {
                    LL root = sqrt(a * a - 4 * z);
                    LL y = (-a + root) / 2;
                    if (y > 0 && (-a + root) % 2 == 0) {
                        LL x = y + a;
                        // 输出答案，结束程序
                        if (x * x * x - y * y * y == N) {
                            cout << x << " " << y << endl;
                            return;
                        }
                    }
                }
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}