// Problem: https://www.acwing.com/problem/content/863/
// 匈牙利算法求二分图的最大匹配

/*
    匈牙利算法思路有点抽象，详细可参考这个网页：
    https://blog.csdn.net/dark_scope/article/details/8880547
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 510, M = 1e5 + 10;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];  // 看n2中的点匹配上了n1的哪个点
bool st[N];    // 临时预定，看当前这一轮中，x点是否被占用

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int next = e[i];
        if (!st[next]) {
            st[next] = true;
            if (match[next] == 0 || find(match[next])) {
                match[next] = x;
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st);
        if (find(i))
            res++;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}