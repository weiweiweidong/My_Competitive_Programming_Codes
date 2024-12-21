// Problem: https://atcoder.jp/contests/abc379/tasks/abc379_f

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, q;
int a[N];     // 存放楼的高度
int s[N], t;  // s[] 用作单调栈, t 表示栈的大小(或当前栈顶位置)
int ans[N];   // 存储最终结果
vector<PII> query[N];  // 存储所有左端点为i的查询

void solve() {
    // 读入数据
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 读入查询
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        /*
        这里的存储方式很技巧：
            index：查询的左端点
            value：pair 存储查询的右端点 和 查询编号
        */
        query[l].push_back({r, i});
    }

    // 从后往前看每一栋楼
    for (int i = n; i > 0; i--) {
        // 取出来左端点为 i 的所有查询
        for (auto p : query[i]) {
            // 在单调栈 s 里二分，找到大于 r 的最小值
            int L = 1, R = t;
            while (L < R) {
                int mid = (L + R + 1) / 2;
                if (s[mid] > p.first)
                    L = mid;
                else
                    R = mid - 1;
            }

            // 说明无解
            if (s[L] <= p.first)
                ans[p.second] = 0;
            // L 就是结果
            else
                ans[p.second] = L;
        }

        while (t && a[s[t]] < a[i])
            t--;
        s[++t] = i;
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}