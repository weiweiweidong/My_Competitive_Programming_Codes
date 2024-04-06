// Problem: https://atcoder.jp/contests/abc347/tasks/abc347_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
LL A[N], appear[N], sum[N];
LL sz;
LL n, q;

void solve() {
    memset(appear, -1, sizeof appear);

    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        int x;
        cin >> x;
        // 插入操作
        if (appear[x] == -1) {
            appear[x] = i;
            sz++;
            sum[i + 1] = sum[i] + sz;
        }
        // 删除操作
        else {
            int t = appear[x];
            appear[x] = -1;
            sz--;
            sum[i + 1] = sum[i] + sz;

            A[x] += sum[i] - sum[t];
        }
    }

    for (int x = 1; x <= n; x++) {
        if (appear[x] != -1) {
            int t = appear[x];
            A[x] += sum[q + 1] - sum[t];
        }
    }

    for (int x = 1; x <= n; x++)
        cout << A[x] << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}