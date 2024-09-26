// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 5010;
int s[N][N];
int n, r;

void solve() {
    cin >> n >> r;
    r = min(5001, r);  // 因为r最大可以取 10^9

    // 读入数据
    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        s[++x][++y] +=
            w;  // 右移一位，就不需要考虑边界；必须是+=，因为一个位置可能有多个目标
    }

    // 处理前缀和
    for (int i = 1; i <= 5001; i++) {
        for (int j = 1; j <= 5001; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
        }
    }

    // 枚举矩形的右下角，求范围内的最大值
    int ans = 0;
    for (int i = r; i <= 5001; i++) {
        for (int j = r; j <= 5001; j++) {
            ans =
                max(ans, s[i][j] - s[i - r][j] - s[i][j - r] + s[i - r][j - r]);
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}