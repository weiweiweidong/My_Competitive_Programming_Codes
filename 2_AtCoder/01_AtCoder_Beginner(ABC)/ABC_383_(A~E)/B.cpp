// Problem: https://atcoder.jp/contests/abc383/tasks/abc383_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 15;
char g[N][N];
bool st[N][N];
int res;
int h, w, d;

int check(int a, int b, int x, int y) {
    int ans = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            if (g[i][j] == '.')
                if (abs(i - a) + abs(j - b) <= d ||
                    abs(i - x) + abs(j - y) <= d) {
                    ans++;
                }

    return ans;
}

void solve() {
    cin >> h >> w >> d;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> g[i][j];

    // 确定第一台的位置
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            // 确定第二台的位置
            for (int x = 0; x < h; x++)
                for (int y = 0; y < w; y++) {
                    // 如果是同一个点，跳过
                    if (i == x && j == y)
                        continue;
                    // 如果两个点都是 地板
                    if (g[i][j] == '.' && g[x][y] == '.') {
                        res = max(res, check(i, j, x, y));
                    }
                }
        }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}