// Problem: https://www.acwing.com/problem/content/425/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int NUM = 110, VOL = 1010;
int f[NUM][VOL];
int vol, num;

void solve() {
    cin >> vol >> num;
    int res = 0;
    int v, w;

    // 遍历数量
    for (int i = 1; i <= num; i++) {
        cin >> v >> w;
        // 遍历体积
        for (int j = 0; j <= vol; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v)
                f[i][j] = max(f[i][j], f[i - 1][j - v] + w);
            res = max(res, f[i][j]);
        }
    }

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}