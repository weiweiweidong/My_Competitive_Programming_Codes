// Problem: https://atcoder.jp/contests/abc302/tasks/abc302_d
// 二分
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL N, M, D;
vector<LL> A, B;

LL cal() {
    LL res = -1;
    for (int i = 0; i < N; i++) {
        int diff = 0;
        LL x = A[i] - D, y = A[i] + D;
        int a = lower_bound(B.begin(), B.end(), x) - B.begin();
        int b = upper_bound(B.begin(), B.end(), y) - B.begin();
        if (b - a)
            res = max(res, A[i] + B[b - 1]);
    }
    return res;
}

void solve() {
    cin >> N >> M >> D;
    A.resize(N);
    B.resize(M);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int j = 0; j < M; j++)
        cin >> B[j];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    LL res = cal();

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}