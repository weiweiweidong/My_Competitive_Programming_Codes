// Problem: https://www.acwing.com/problem/content/901/
// 最短编辑距离的应用
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
int n, m;
string A[N], B[N];
int limits[N];

// 计算从a变到b的最短编辑距离
int edit_distance(string a, string b) {
    int as = a.size(), bs = b.size();
    a = " " + a, b = " " + b;
    int f[N][N];
    for (int i = 0; i <= as; i++)
        f[i][0] = i;
    for (int i = 0; i <= bs; i++)
        f[0][i] = i;

    for (int i = 1; i <= as; i++)
        for (int j = 1; j <= bs; j++) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            if (a[i] == b[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }

    return f[as][bs];
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= m; i++)
        cin >> B[i] >> limits[i];

    // 遍历每一次查询
    for (int j = 1; j <= m; j++) {
        int res = 0;
        // 遍历A里的每一个字符串
        for (int i = 1; i <= n; i++)
            // 如果最短编辑距离在 x 以内
            if (edit_distance(A[i], B[j]) <= limits[j])
                res++;
        cout << res << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}