// Problem: https://atcoder.jp/contests/abc356/tasks/abc356_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int cnt[N];
int sum[N];
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int i = 1; i <= 1e6 + 1; i++)
        sum[i] = sum[i - 1] + cnt[i];

    LL res = 0;
    for (int num = 1; num <= 1e6; num++) {
        // t 是当前数字的出现数量
        int t = cnt[num];

        for (int k = 1; 1ll * k * num <= 1000000; k++) {
            int r = min(1000001, (k + 1) * num - 1);
            int l = k * num - 1;

            // 特判
            if (k == 1 && t) {
                res += 1ll * t * (t - 1) / 2;
                res += 1ll * (sum[r] - sum[l] - t) * t;
            }
            // 其余状态
            else
                res += 1ll * k * (sum[r] - sum[l]) * t;
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