// Problem: https://atcoder.jp/contests/abc394/tasks/abc394_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 55;
int n;
string s[N];

// 自定义 cmp 算子
bool cmp(string& a, string& b) {
    return a.size() < b.size();
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    // 升序排序
    sort(s, s + n, cmp);

    // 从前往后输出
    for (int i = 0; i < n; i++)
        cout << s[i];
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}