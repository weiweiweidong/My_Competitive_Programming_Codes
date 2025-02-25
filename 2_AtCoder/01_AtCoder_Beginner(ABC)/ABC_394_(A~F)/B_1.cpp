// Problem: https://atcoder.jp/contests/abc394/tasks/abc394_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 55;
string s[N];
PII tmp[N];  // 存储 字符串长度 和 字符串编号
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        // 把 {字符串长度，字符串编号} 存入 tmp
        tmp[i] = {s[i].size(), i};
    }
    // 按照字符串长度升序排列
    sort(tmp, tmp + n);
    // 输出
    for (int i = 0; i < n; i++)
        cout << s[tmp[i].second];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}