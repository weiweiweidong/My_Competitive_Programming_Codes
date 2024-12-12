// Problem: https://atcoder.jp/contests/abc363/tasks/abc363_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int cnt[N];
int n, t, p;

void solve() {
    cin >> n >> t >> p;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int i = 1; i < N; i++)
        cnt[i] += cnt[i - 1];

    // 遍历长度
    for (int len = 100; len >= 0; len--)
        // 长度为 i 以上的人数达到了 p 人
        if (cnt[100] - cnt[len - 1] >= p) {
            cout << max(0, t - len) << endl;
            break;
        }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}