// Problem: https://www.acwing.com/problem/content/801/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int q[N], s[N];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];

    int res = -1;
    for (int i = 0, j = 0; i < n; i++) {
        s[q[i]]++;
        while (j < i && s[q[i]] > 1) {
            s[q[j]]--;
            j++;
        }
        res = max(i - j + 1, res);
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}