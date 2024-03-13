// Problem: https://www.acwing.com/problem/content/156/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n, k;
int q[N], a[N], hh, tt;

// 队列初始化
void init() {
    hh = 0, tt = -1;
}

void solve() {
    // 读入数据
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // 找窗口最小值
    init();
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        tt++;
        q[tt] = i;
        if (i >= k - 1)
            cout << a[q[hh]] << " ";
    }
    cout << endl;

    // 找窗口最大值
    init();
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh])
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        tt++;
        q[tt] = i;
        if (i >= k - 1)
            cout << a[q[hh]] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}