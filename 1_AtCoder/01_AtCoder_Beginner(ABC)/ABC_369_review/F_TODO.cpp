// Problem: https://atcoder.jp/contests/abc369/tasks/abc369_f
// 经典的用数据结构优化DP

// 还没有学明白是怎么回事

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define MP std::make_pair

const int MAXN = 2e5 + 5;
PII pos[MAXN];
int h, w, n;
int pre[MAXN];

// 树状数组
struct BIT {
#define lowbit(x) ((x) & (-(x)))
    PII tree[MAXN];

    void add(int p, PII x) {
        while (p < MAXN) {
            tree[p] = std::max(tree[p], x);
            p += lowbit(p);
        }
    }

    PII query(int p) {
        PII res = MP(0, 0);
        while (p) {
            res = std::max(res, tree[p]);
            p -= lowbit(p);
        }
        return res;
    }
} bit;

void solve() {
    scanf("%d%d%d", &h, &w, &n);
    FOR(i, 1, n) scanf("%d%d", &pos[i].fi, &pos[i].se);
    pos[0] = MP(1, 1);
    pos[n + 1] = MP(h, w);
    std::sort(pos + 1, pos + n + 1);
    FOR(i, 1, n + 1) {
        auto tmp = bit.query(pos[i].se);
        bit.add(pos[i].se, MP(tmp.fi + 1, i));
        pre[i] = tmp.se;
        if (i == n + 1) {
            printf("%d\n", tmp.fi);
        }
    }
    int now = n + 1;
    vector<char> vec;
    while (now) {
        int dx = pos[now].fi - pos[pre[now]].fi,
            dy = pos[now].se - pos[pre[now]].se;
        while (dx--)
            vec.pb('D');
        while (dy--)
            vec.pb('R');
        now = pre[now];
    }
    std::reverse(all(vec));
    for (auto x : vec) {
        putchar(x);
    }
    puts("");
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}