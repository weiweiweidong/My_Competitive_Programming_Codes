// Problem: https://atcoder.jp/contests/abc395/tasks/abc395_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 55;
char res[N][N];
int n;

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int j = n + 1 - i;
        if (i > j)
            break;
        // 涂满(i,i) 到 (j,j) 区域
        char c = (i & 1) ? '#' : '.';
        for (int x = i; x <= j; x++)
            for (int y = i; y <= j; y++)
                res[x][y] = c;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
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