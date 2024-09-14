// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int L, R;
    cin >> L >> R;

    if (L && !R)
        cout << "Yes" << endl;
    else if (!L && R)
        cout << "No" << endl;
    else
        cout << "Invalid" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}