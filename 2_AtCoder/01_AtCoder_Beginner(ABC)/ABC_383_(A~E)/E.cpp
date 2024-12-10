// Problem: https://atcoder.jp/contests/abc383/tasks/abc383_e

// 并查集 + 贪心
// 本题和ACW506非常的类似：
// https://www.acwing.com/problem/content/description/508/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

struct Edge {
    int w;
    int u, v;
} e[N];

bool cmp(Edge& a, Edge& b) {
    return a.w < b.w ? true : false;
}

int A[N], B[N];
int cnta[N], cntb[N];  // 连通块中，未匹配的A和B各个元素的数目
int p[N];              // 并查集数组，存储每个元素的祖宗元素
int n, m, k;

// 找到 x 的祖宗节点
int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

// 计算x和y点相连，能匹配成功多少对点
int merge(int x, int y) {
    // 求 x 和 y 的根节点
    int px = find(x), py = find(y);
    // 如果相同，说明他们已经在一个连通块了，不能再匹配了
    if (px == py)
        return 0;
    // 把 x 并入 y 中
    p[px] = py;
    // 将 px 连通块的 AB 计数加到 py 上
    cnta[py] += cnta[px];
    cntb[py] += cntb[px];

    // 合并完成后，看看在 fy 为根的连通块中有多少对可以A与B相匹配
    int tmp = min(cnta[py], cntb[py]);

    // 匹配完成，把匹配掉的A和B减掉。（因为已经成对了，不是未匹配的状态）
    cnta[py] -= tmp;
    cntb[py] -= tmp;

    // 返回这一次匹配成功了多少个点
    return tmp;
}

void solve() {
    cin >> n >> m >> k;
    // 读入所有的边
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[i] = {c, a, b};
    }
    // 储存 A 和 B
    for (int i = 0; i < k; i++)
        cin >> A[i];
    for (int i = 0; i < k; i++)
        cin >> B[i];
    // 并查集初始化
    for (int i = 1; i <= n; i++)
        p[i] = i;
    // 按照边权升序排列
    sort(e, e + m, cmp);

    // 预处理A和B中，每个元素的数量，存在cnta和cntb中
    for (int i = 0; i < k; i++) {
        cnta[A[i]]++;
        cntb[B[i]]++;
    }

    // 遍历每一条边
    LL res = 0;
    for (int i = 0; i < m; i++) {
        // 看加入i边后，能匹配多少对
        res += merge(e[i].u, e[i].v) * e[i].w;
    }

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}