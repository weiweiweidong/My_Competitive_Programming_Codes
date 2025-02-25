// Problem: https://atcoder.jp/contests/abc394/tasks/abc394_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;
int cnt;

void solve() {
    cin >> s;
    for (auto x : s)
        if (x == '2')
            cnt++;  // 计算有多少个 2
    // 输出
    cout << string(cnt, '2') << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}