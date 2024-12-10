// Problem: https://atcoder.jp/contests/abc187/tasks/abc187_d

// 贪心
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
LL A, B;
int n;

struct Vote {
    int a, b;
    LL dif;
} v[N];

bool cmp(Vote& x, Vote& y) {
    return x.dif > y.dif ? true : false;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y, 2ll * x + y};
        A += x;
    }

    sort(v, v + n, cmp);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (B > A) {
            break;
        }
        res++;
        B += v[i].dif;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}