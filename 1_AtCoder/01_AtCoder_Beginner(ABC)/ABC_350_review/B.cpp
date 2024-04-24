// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
bool tooth[N];

void solve() {
    int n, q;
    cin >> n >> q;
    memset(tooth, true, sizeof tooth);

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (tooth[t])
            tooth[t] = false;
        else
            tooth[t] = true;
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        if (tooth[i])
            res++;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}