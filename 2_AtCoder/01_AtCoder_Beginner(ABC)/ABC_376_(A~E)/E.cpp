// Problem: https://atcoder.jp/contests/abc376/tasks/abc376_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 2e5 + 10;
int T, K, N;
PII A[MAXN];
priority_queue<int> Q;  // 大根堆
LL ans, sum;

void solve() {
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
            cin >> A[i].first;
        for (int i = 1; i <= N; i++)
            cin >> A[i].second;
        // 排序
        sort(A + 1, A + N + 1);
        // 初始化
        ans = 1e18, sum = 0;
        // 清空堆 （注：priority_queue没有clear函数）
        while (!Q.empty())
            Q.pop();

        // 处理前 K-1 个数
        for (int i = 1; i < K; i++) {
            Q.push(A[i].second);
            sum += (LL)A[i].second;
        }

        // 从第 K 个数开始
        for (int i = K; i <= N; i++) {
            sum += (LL)A[i].second;
            ans = min(ans, (LL)A[i].first * sum);
            Q.push(A[i].second);
            // 把看过的 B 的最大值弹出来去掉，就能保证 sum 的值是最小的
            sum -= (LL)Q.top();
            Q.pop();
        }

        cout << ans << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}