// Problem: https://atcoder.jp/contests/abc394/tasks/abc394_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 55;
string s[N];
PII tmp[N];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        tmp[i] = {s[i].size(), i};
    }

    sort(tmp, tmp + n);
    for (int i = 0; i < n; i++)
        cout << s[tmp[i].second];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}