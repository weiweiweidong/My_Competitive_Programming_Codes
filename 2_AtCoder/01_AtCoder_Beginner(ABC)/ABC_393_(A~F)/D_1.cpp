// Problem: https://atcoder.jp/contests/abc393/tasks/abc393_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;

void solve() {
    cin >> n >> s;
    // 预处理一下总共有多少 1
    int tot_1 = 0;
    for (auto x : s)
        tot_1 += (x == '1');

    LL res = 0;
    int left = 0;  // 左侧有多少 1
    for (char c : s)
        // 如果遇到 0
        if (c == '0')
            res += min(left, tot_1 - left);
        // 如果遇到 1
        else
            left++;

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}