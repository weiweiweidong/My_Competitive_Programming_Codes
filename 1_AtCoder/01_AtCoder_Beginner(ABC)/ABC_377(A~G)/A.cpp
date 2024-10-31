// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int v[26];

void solve() {
    string S;
    cin >> S;
    for (auto x : S)
        v[x - 'A']++;

    if (v[0] == 1 && v[1] == 1 && v[2] == 1)
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