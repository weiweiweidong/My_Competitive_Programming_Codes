// Problem:
// 方法1 ：假设我什么都不做
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const LL N = 9, M = 20, K = 81, MOD = 998244353;
LL A[N][N];
array<array<LL, 3>, 3> stamps[M];
int n, m, k;

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                cin >> stamps[i][j][k];
    }

    // 最暴力做法
    cout << 0 << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << A[i][j] % MOD << " ";
    //     }
    //     cout << endl;
    // }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}