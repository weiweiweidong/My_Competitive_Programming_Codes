// Problem: https://atcoder.jp/contests/abc328/tasks/abc328_c

// 计算字符串 S 的 [L,R] 区间内有多少个连续两次相同的字符
// 二分
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int N = 3e5 + 10;
string S;
int T;
int n;
int l, r;

void solve() {
    cin >> n >> T >> S;
    vector<int> pos;
    for (int i = 0; i < n - 1; i++)
        if (S[i] == S[i + 1])
            pos.push_back(i + 1);

    while (T--) {
        cin >> l >> r;
        int pos1 = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
        int pos2 = lower_bound(pos.begin(), pos.end(), r) - pos.begin();

        cout << pos2 - pos1 << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}