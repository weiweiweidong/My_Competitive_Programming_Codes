// Problem: https://www.acwing.com/problem/content/239/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 注：最大有1e5个约束条件，每个条件描述2个点的关系。极端情况下需要2e5个点才够
const int N = 2e5 + 10;
int T;
int cnt;  // 有 cnt 个点，（离散化用）
int n;    // 有 n 个约束条件
int p[N];
unordered_map<int, int> S;

// 构造结构体，保存的是约束条件
struct Query {
    int x, y, e;
} query[N];

// 非保序性离散化：很简单，只需要 unordered_map 就行
// 获取x离散化后的值
int get(int x) {
    if (S.count(x) == 0)
        S[x] = ++cnt;
    return S[x];
}

// 并查集：求x的祖宗节点
int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

// 主程序
void answer() {
    // 初始化，
    cnt = 0;
    S.clear();
    // 读入n条约束条件
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, e;
        cin >> x >> y >> e;
        query[i] = {get(x), get(y), e};
    }

    // 并查集初始化
    for (int i = 1; i <= cnt; i++)
        p[i] = i;

    // 合并所有的相等约束
    for (int i = 0; i < n; i++) {
        if (query[i].e == 1) {
            int pa = find(query[i].x);
            int pb = find(query[i].y);
            p[pa] = pb;
        }
    }

    // 检查所有的不等约束
    bool has_conflict = false;
    for (int i = 0; i < n; i++) {
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

void solve() {
    cin >> T;
    while (T--)
        answer();
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}