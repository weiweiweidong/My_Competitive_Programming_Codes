// Problem: https://atcoder.jp/contests/abc381/tasks/abc381_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;

void solve() {
    cin >> n >> s;

    if (n % 2 != 1)
        cout << "No" << endl;
    else {
        string res = string(n / 2, '1') + "/" + string(n / 2, '2');
        if (s != res)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}