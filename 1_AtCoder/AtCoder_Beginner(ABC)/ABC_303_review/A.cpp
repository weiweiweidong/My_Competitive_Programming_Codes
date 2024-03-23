// Problem: https://atcoder.jp/contests/abc303/tasks/abc303_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int N;
    string S, T;
    cin >> N >> S >> T;
    for (auto& x : S) {
        if (x == '1')
            x = 'l';
        if (x == '0')
            x = 'o';
    }
    for (auto& x : T) {
        if (x == '1')
            x = 'l';
        if (x == '0')
            x = 'o';
    }

    if (S == T)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}