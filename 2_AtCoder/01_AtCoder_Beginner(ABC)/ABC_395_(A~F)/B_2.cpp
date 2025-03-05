// Problem: https://atcoder.jp/contests/abc395/tasks/abc395_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 55;
int n;
char res[N][N];

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        // 预处理出来 j 的值
        int j = n + 1 - i;
        // 如果越界
        if (i > j)
            break;
        // 确定要填充的符号
        char c = (i & 1) ? '#' : '.';
        // 填充四条边
        for (int k = i; k <= j; k++) {
            // (i,i) -> (i,j) 上边界
            // (i,i) -> (j,i) 左边界
            res[i][k] = res[k][i] = c;
            // (i,j) -> (j,j) 右边界
            // (j,i) -> (j,j) 下边界
            res[k][j] = res[j][k] = c;
        }
    }

    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << res[i][j];
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}