// Problem: https://atcoder.jp/contests/abc382/tasks/abc382_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = n - 1; i >= 0; i--) {
        if (!k)
            break;
        if (s[i] == '@') {
            k--;
            s[i] = '.';
        }
    }

    cout << s << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}