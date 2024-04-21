// Problem: https://www.acwing.com/problem/content/5574/
// DP:状态机

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
int w[N];
string s[N][2];
LL f[N][2];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++) {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }

    memset(f, 0x3f, sizeof f);
    f[0][0] = 0, f[0][1] = w[0];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                // 字符串是可以直接按照字典序判别大小的
                if (s[i][j] >= s[i - 1][k])
                    f[i][j] = min(f[i][j], f[i - 1][k] + j * w[i]);

    LL res = min(f[n - 1][0], f[n - 1][1]);
    if (res == 0x3f3f3f3f3f3f3f3f)
        res = -1;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}