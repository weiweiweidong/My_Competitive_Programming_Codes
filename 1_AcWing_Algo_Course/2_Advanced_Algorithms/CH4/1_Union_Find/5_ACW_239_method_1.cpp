// 带边权的写法

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 20010;
int n, m;
int p[N], d[N];
unordered_map<int, int> S;  // 离散化

int get(int x) {
    if (S.count(x) == 0)
        S[x] = ++n;
    return S[x];
}

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}

int main() {
    cin >> n >> m;
    n = 0;
    // 并查集初始化
    for (int i = 0; i <= N; i++)
        p[i] = i;

    int res = m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        string type;
        cin >> a >> b >> type;
        // 获取离散化后的值
        a = get(a - 1), b = get(b);

        int t = 0;
        if (type == "odd")
            t = 1;
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            if (((d[a] + d[b]) % 2 + 2) % 2 != t) {
                res = i - 1;
                break;
            }
        } else {
            p[pa] = pb;
            d[pa] = d[a] ^ d[b] ^ t;
        }
    }
    cout << res << endl;
}