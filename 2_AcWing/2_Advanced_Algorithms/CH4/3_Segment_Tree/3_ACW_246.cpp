// Problem: https://www.acwing.com/problem/content/247/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;
int n, m;
LL w[N];
struct Node {
    int l, r;
    LL sum, d;
} tr[4 * N];
LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}
void pushup(Node& u, Node& l, Node& r) {
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}
void pushup(int u) {
    pushup(tr[u], tr[u * 2], tr[u * 2 + 1]);
}
void build(int u, int l, int r) {
    if (l == r) {
        LL b = w[r] - w[r - 1];
        tr[u] = {l, r, b, b};
    } else {
        tr[u].l = l, tr[u].r = r;
        int mid = (l + r) >> 1;
        build(u * 2, l, mid), build(u * 2 + 1, mid + 1, r);
        pushup(u);
    }
}
void modify(int u, int x, LL v) {
    if (tr[u].l == x && tr[u].r == x) {
        LL b = tr[u].sum + v;
        tr[u] = {x, x, b, b};
    } else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid)
            modify(u * 2, x, v);
        else
            modify(u * 2 + 1, x, v);
        pushup(u);
    }
}
Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (r <= mid)
            return query(u * 2, l, r);
        else if (l > mid)
            return query(u * 2 + 1, l, r);
        else {
            auto left = query(u * 2, l, r);
            auto right = query(u * 2 + 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    build(1, 1, n);

    int l, r;
    LL d;
    char op[2];
    while (m--) {
        scanf("%s%d%d", op, &l, &r);
        if (*op == 'Q') {
            auto left = query(1, 1, l);
            Node right = {0, 0, 0, 0};
            if (l + 1 <= r)
                right = query(1, l + 1, r);
            cout << abs(gcd(left.sum, right.d)) << endl;
        } else {
            cin >> d;
            modify(1, l, d);
            if (r + 1 <= n)
                modify(1, r + 1, -d);
        }
    }
}
