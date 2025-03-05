// Problem: https://atcoder.jp/contests/abc045/tasks/arc061_a

// 这道题目和 ABC_197_C 的分隔思路一模一样。
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string S;
int n;

void solve() {
    cin >> S;
    n = S.size();

    LL res = 0;
    // 枚举所有的分隔状态
    for (int st = 0; st < (1 << (n - 1)); st++) {
        LL num = 0;
        for (int i = 0; i <= n; i++) {
            if (i < n) {
                LL p = S[i] - '0';
                num = num * 10 + p;
            }
            if (i == n || (st >> i) & 1) {
                res += num;
                num = 0;
            }
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}