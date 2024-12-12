// Problem: https://atcoder.jp/contests/abc363/tasks/abc363_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
string s;

// 快速判断回文
bool check(int l, int r) {
    while (l < r)
        if (s[l++] != s[r--])
            return 0;
    return 1;
}

void solve() {
    cin >> n >> k;
    cin >> s;
    sort(s.begin(), s.end());

    int res = 0;
    int len = s.size();
    do {
        bool can = true;
        for (int i = 0; i + k - 1 < len; i++) {
            if (check(i, i + k - 1)) {
                can = false;
                break;
            }
        }
        if (can)
            res++;
    } while (next_permutation(s.begin(), s.end()));
    // 备注：next_permutation 在用的时候会自动去重

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}