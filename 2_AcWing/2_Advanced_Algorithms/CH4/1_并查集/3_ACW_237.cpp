#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2000010;
int n, m;
int p[N];
unordered_map<int, int> S;

// 构造结构体，保存的是约束条件
struct Query {
    int x, y, e;
} query[N];

// 获取x离散化后的值
int get(int x) {
    if (S.count(x) == 0)
        S[x] = ++n;
    return S[x];
}

// 并查集：求x的祖宗节点
int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

// 主程序
void solve() {
    // 初始化，并读入m条限制条件
    n = 0;
    S.clear();
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int x, y, e;
        scanf("%d%d%d", &x, &y, &e);
        query[i] = {get(x), get(y), e};
    }

    // 并查集初始化
    for (int i = 1; i <= n; i++)
        p[i] = i;

    // 合并所有的相等约束
    for (int i = 0; i < m; i++) {
        if (query[i].e == 1) {
            int pa = find(query[i].x);
            int pb = find(query[i].y);
            p[pa] = pb;
        }
    }

    // 检查所有的不等条件
    bool has_conflict = false;
    for (int i = 0; i < m; i++) {
        if (query[i].e == 0) {
            int pa = find(query[i].x);
            int pb = find(query[i].y);
            if (pa == pb) {
                has_conflict = true;
                break;
            }
        }
    }

    if (has_conflict)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}