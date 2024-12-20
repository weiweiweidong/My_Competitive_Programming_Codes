// Problem: https://atcoder.jp/contests/abc379/tasks/abc379_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;
int n, k;

void solve() {
    cin >> n >> k >> s;

    string gd(k, 'O');  // 健康牙齿的 pattern
    string bd(k, 'X');  // 蛀牙的 pattern

    int res = 0;
    // 找健康牙齿的 pattern
    while (s.find(gd) != s.npos) {
        s.replace(s.find(gd), k, bd);  // 替换成蛀牙 pattern
        res++;                         // 计数
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}