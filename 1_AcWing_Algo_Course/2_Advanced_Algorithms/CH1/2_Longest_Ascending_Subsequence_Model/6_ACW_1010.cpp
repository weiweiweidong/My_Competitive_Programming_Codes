// Problem: https://www.acwing.com/problem/content/1012/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
int n;
int h[N], f[N];

void solve() {
    while (cin >> h[n])
        n++;

    // 问题1:求最长非上升子序列长度
    int res = 0;
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (h[i] <= h[j])
                f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }
    cout << res << endl;
    // -------------------------------------------------------------------
    // 问题2：需要多少个非上升子序列才能覆盖所有元素
    // 方法1:使用普通的数组
    int cnt = 0;
    int g[N];
    for (int i = 0; i < n; i++) {
        // lower_bound 返回第一个大于等于 h[i] 的位置
        // 因为导弹可以打到相同的高度，就不用占据后面一个元素的位置了
        int pos = lower_bound(g, g + cnt, h[i]) - g;
        // 如果搜到底了，就新添加一个元素
        if (pos == cnt)
            g[cnt++] = h[i];
        // 否则就更新一下这个元素
        else
            g[pos] = h[i];
    }
    cout << cnt << endl;

    // 方法2:使用vector数组
    // vector<int> g;
    // for( int i = 0 ; i < n ; i++ ){
    //     int pos = lower_bound( g.begin() , g.end() , h[i] ) - g.begin();
    //     if( pos == g.size() ) g.push_back(h[i]);
    //     else g[pos] = h[i];
    // }
    // cout << g.size() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}