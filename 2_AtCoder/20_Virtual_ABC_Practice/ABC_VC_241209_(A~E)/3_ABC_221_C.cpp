// Problem: https://atcoder.jp/contests/abc221/tasks/abc221_c

// STL的使用：
// 字符串sort，next_permutation, substr, stol, stoi 的使用
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string S;
int n;
LL res;

void solve() {
    cin >> S;
    int n = S.size();
    sort(S.begin(), S.end());

    do {
        for (int len = 1; len < n; len++) {
            LL a = stol(S.substr(0, len));
            LL b = stol(S.substr(len));
            res = max(res, a * b);
        }
    } while (next_permutation(S.begin(), S.end()));

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}