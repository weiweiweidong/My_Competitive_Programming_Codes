// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
string S[N], S_inv[N];
LL cost[N];
LL f[N][2];

int cmp(string a, string b) {
    if (a == b)
        return 0;

    int i = -1;
    while (true) {
        i++;
        if (i < a.size() && i < b.size()) {
            if (a[i] > b[i])
                return -1;
            else if (a[i] < b[i])
                return 1;
        } else if (i < a.size())
            return -1;
        else if (i < b.size())
            return 1;
        else
            return 0;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        S[i] = t;
        reverse(t.begin(), t.end());
        S_inv[i] = t;
    }

    memset(f, -1, sizeof f);
    f[0][0] = f[0][1] = f[1][0] = 0;
    f[1][1] = cost[1];

    bool flag = false;  // 判断是否不成立

    for (int i = 2; i <= n; i++) {
        // 前一个位置不变，当前位置不变
        if (cmp(S[i - 1], S[i]) >= 0 && f[i - 1][0] != -1)
            f[i][0] = f[i - 1][0];
        // 前一个位置变，当前位置不变
        if (cmp(S_inv[i - 1], S[i]) >= 0 && f[i - 1][1] != -1) {
            if (f[i][0] == -1)
                f[i][0] = f[i - 1][1];
            else
                f[i][0] = min(f[i][0], f[i - 1][1]);
        }
        // 前一个位置不变，当前位置变
        if (cmp(S[i - 1], S_inv[i]) >= 0 && f[i - 1][0] != -1)
            f[i][1] = f[i - 1][0] + cost[i];
        // 前一个位置变，当前位置变
        if (cmp(S_inv[i - 1], S_inv[i]) >= 0 && f[i - 1][1] != -1) {
            if (f[i][1] == -1)
                f[i][1] = f[i - 1][1] + cost[i];
            else
                f[i][1] = min(f[i][1], f[i - 1][1] + cost[i]);
        }

        if (f[i][0] == -1 && f[i][1] == -1) {
            flag = false;
            break;
        }
    }

    if (f[n][0] == -1 && f[n][1] == -1)
        cout << -1 << endl;
    else if (f[n][0] != -1 && f[n][1] != -1)
        cout << min(f[n][0], f[n][1]) << endl;
    else
        cout << max(f[n][0], f[n][1]) << endl;
}

void solve2() {
    string a, b;
    cin >> a >> b;
    cout << cmp(a, b) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    // solve2();
    return 0;
}