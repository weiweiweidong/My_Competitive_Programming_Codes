// Problem:

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
        for (int i = 0; i < N; i++)
            cin >> A[i].first;
        for (int i = 0; i < N; i++)
            cin >> A[i].second;
        // 排序
        sort(A, A + N);
        // 初始化
        ans = 1e18, sum = 0;
        while (!Q.empty())  // 清空堆
            Q.pop();

        // 处理前 K-1 个数
        for (int i = 0; i < K - 1; i++) {
            Q.push(A[i].second);
            sum += (LL)A[i].second;
        }

        // 从第 K 个数开始
        for (int i = K - 1; i < N; i++) {
            sum += (LL)A[i].second;
            ans = min(ans, sum * (LL)A[i].first);
            Q.push(A[i].second);
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