// Problem: https://www.acwing.com/problem/content/1019/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int n;
int h[N], f[N];

void solve() {
    int T;
    cin >> T;
    while (T--) {
        // 读入当前组数据
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> h[i];

        int res = 0;
        // 正向遍历一遍，求解
        for (int i = 1; i <= n; i++) {
            f[i] = 1;
            for (int j = 1; j < i; j++) {
                if (h[i] > h[j])
                    f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }

        // 反向遍历一遍，求解
        for (int i = n; i >= 1; i--) {
            f[i] = 1;
            for (int j = n; j > i; j--) {
                if (h[i] > h[j])
                    f[i] = max(f[i], f[j] + 1);
            }
            res = max(res, f[i]);
        }

        // 输出结果
        cout << res << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}