// Problem: https://www.acwing.com/problem/content/5564/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, x;

void solve() {
    cin >> n;
    int res = 0;
    while (n--) {
        cin >> x;
        if (x)
            res++;
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}