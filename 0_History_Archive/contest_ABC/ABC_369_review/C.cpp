// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int val[N];

void solve() {
    int n;
    cin >> n;

    LL res = n;

    for (int i = 0; i < n; i++)
        cin >> val[i];

    for (int i = 1; i < n; i++) {
        int d = val[i] - val[i - 1];
        int k = i;
        while (k + 1 < n && val[k + 1] - val[k] == d)
            k++;
        res += (LL)(k - i + 2) * (k - i + 1) / 2;
        i = k;
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}