#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
const ll modd = 998244353;
const ll inf = 1e18;

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % modd;
        a = a * a % modd;
        b >>= 1;
    }
    return res;
}
inline ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll n;
inline void solve() {
    cin >> n;
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x < 0)
            res += (-x);
        else
            res += x;
    }
    cout << res << endl;
}
inline void pre_work() {}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    pre_work();

    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}