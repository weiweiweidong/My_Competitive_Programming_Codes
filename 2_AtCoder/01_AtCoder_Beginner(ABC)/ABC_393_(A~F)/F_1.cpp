// Problem: https://atcoder.jp/contests/abc393/tasks/abc393_f

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

int n, q;
int a[N];
struct Query {
    int x, id;
};
vector<Query> qs[N];

// 处理离散化
void disc() {
    vector<int> all_nums;
    for (int i = 1; i <= n; i++)
        all_nums.push_back(a[i]);
    for (int i = 1; i <= n; i++)
        for (Query q : qs[i])
            all_nums.push_back(q.x);
    sort(all_nums.begin(), all_nums.end());
    all_nums.resize(unique(all_nums.begin(), all_nums.end()) -
                    all_nums.begin());
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(all_nums.begin(), all_nums.end(), a[i]) -
               all_nums.begin() + 1;
    for (int i = 1; i <= n; i++)
        for (Query& q : qs[i])
            q.x = lower_bound(all_nums.begin(), all_nums.end(), q.x) -
                  all_nums.begin() + 1;
}

struct BIT {
    int a[N * 2];

    int lowbit(int x) { return x & -x; }
    void update(int pos, int v) {
        for (; pos < N * 2; pos += lowbit(pos))
            a[pos] = max(a[pos], v);
    }
    int get_max(int pos) {
        int res = 0;
        for (; pos; pos -= lowbit(pos))
            res = max(res, a[pos]);
        return res;
    }
};
BIT bit;
int res[N];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= q; i++) {
        int r, x;
        cin >> r >> x;
        qs[r].push_back({x, i});
    }

    disc();
    for (int i = 1; i <= n; i++) {
        int cur_ai_res = bit.get_max(a[i] - 1) + 1;
        bit.update(a[i], cur_ai_res);

        for (Query q : qs[i]) {
            res[q.id] = bit.get_max(q.x);
        }
    }

    for (int i = 1; i <= q; i++)
        cout << res[i] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}