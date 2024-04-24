// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    string S;
    cin >> S;
    int x = stoi(S.substr(3));
    // cout << x << endl;
    if (x >= 1 && x <= 349 && x != 316)
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