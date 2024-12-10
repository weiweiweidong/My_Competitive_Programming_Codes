// Problem: https://atcoder.jp/contests/abc381/tasks/abc381_e

// 前缀和 + 2次二分
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5;
int a[N], c[N];  // 分别记录 '1' '2' 的前缀和（出现次数）
int n, q;
string s;
int v[N];  // 存储每个/的位置

bool check(int mid, int L, int R) {
    // 计算 mid 左边 1 出现的次数
    int num_1 = a[mid] - a[L - 1];
    // 计算 mid 右边 2 出现的次数
    int num_2 = c[R] - c[mid];
    return num_1 >= num_2;
}

void solve() {
    cin >> n >> q >> s;
    s = " " + s;

    // 预处理前缀和数组
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1], c[i] = c[i - 1];
        if (s[i] == '1')
            a[i]++;
        if (s[i] == '/') {
            v[cnt++] = i;
        }
        if (s[i] == '2')
            c[i]++;
    }
    int n;

    // 存储每个查询
    vector<PII> k;
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        k.push_back({L, R});
    }

    // 遍历每一个查询
    for (auto t : k) {
        int res = 0;
        int L = t.first, R = t.second;

        // 找到 [L,R] 范围内 '/' 的出现范围
        int l = lower_bound(v, v + cnt, L) - v;
        int r = upper_bound(v, v + cnt, R) - v - 1;

        // 如果区间内没有 ‘/’，直接输出 0
        if (r < l) {
            cout << 0 << endl;
            continue;
        }

        // 找到 左侧1数量 大于等于 右侧2数量 的最小值
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(v[mid], L, R))
                r = mid;
            else
                l = mid + 1;
        }

        int len = min(a[v[l]] - a[L - 1], c[R] - c[v[l]]);
        // 看一下前面那个点的情况，取长度的最大值
        if (l - 1 >= 0 && v[l - 1] >= L)
            len = max(len, min(a[v[l - 1]] - a[L - 1], c[R] - c[v[l - 1]]));

        res = 2 * len + 1;
        cout << res << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}