// Problem: https://atcoder.jp/contests/abc395/tasks/abc395_f

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
LL U[N], D[N];
LL n, X;

bool chk(LL H) {
    // L[i]: max(H-D[i] , 0)
    // R[i]: U[i]
    LL lst_L = max(H - D[1], 0ll), lst_R = U[1];
    for (int i = 2; i <= n; i++) {
        // 使用了下面的两个条件：
        // 条件 1：max(H-D[i] ,0) <= U'[i] <= U[i]
        // 条件 2：lst_L - X <= U'[i] <= lst_R + X
        lst_L = max({lst_L - X, H - D[i], 0ll});
        lst_R = min(U[i], lst_R + X);
        if (lst_L > lst_R)
            return false;
    }
    return true;
}

void solve() {
    // 变量初始化
    LL l = 0, r = 2e9;  // 左右范围
    LL res = -1;        // 结果
    LL sm = 0;          // 求和

    // 读入数据
    cin >> n >> X;
    for (int i = 1; i <= n; i++) {
        // 读入 U 和 D 的值
        cin >> U[i] >> D[i];
        // 更新 右范围 和 总和
        r = min(r, U[i] + D[i]);
        sm += U[i] + D[i];
    }

    // 二分
    while (l <= r) {
        LL mid = (l + r) >> 1;
        if (chk(mid))
            res = mid, l = mid + 1;
        else
            r = mid - 1;
    }

    // 输出结果
    cout << sm - n * res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}