#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 30010;
int m;
// sz 表示集合的大小，d[x] 表示x到p[x]的距离
int p[N], sz[N], d[N];

int find(int x) {
    // 路径压缩
    if (p[x] != x) {
        int root = find(p[x]);  // 找到祖宗节点
        d[x] += d[p[x]];        // 更新x到祖宗节点的距离
        p[x] = root;            // 更新x的祖宗节点
    }
    return p[x];  // 返回x的祖宗节点
}

int main() {
    // 读入数据+并查集初始化
    scanf("%d", &m);
    for (int i = 1; i < N; i++) {
        p[i] = i;
        sz[i] = 1;
    }

    while (m--) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        // 合并（把a接到b后面）
        if (op[0] == 'M') {
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                d[pa] = sz[pb];    // pb的尺寸就是pa到祖宗的距离
                sz[pb] += sz[pa];  // pa集合的尺寸加进pb中
                p[pa] = pb;        // pb成为pa的祖宗
            }
        }
        // 查询
        else {
            // 找到a和b的祖宗节点
            int pa = find(a), pb = find(b);
            if (pa != pb)
                puts("-1");
            else
                printf("%d\n", max(0, abs(d[a] - d[b]) - 1));
        }
    }
    return 0;
}