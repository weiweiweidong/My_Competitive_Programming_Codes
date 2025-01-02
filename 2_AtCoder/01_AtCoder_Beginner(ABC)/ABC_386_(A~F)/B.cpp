// Problem: https://atcoder.jp/contests/abc386/tasks/abc386_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;

void solve() {
    cin >> s;

    // 把所有的 00 转化为 1
    while (s.find("00") != s.npos)
        s.replace(s.find("00"), 2, "1");

    // 输出答案
    cout << s.size() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}