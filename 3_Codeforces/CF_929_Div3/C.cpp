#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lll __int128
const ll modd = 998244353;
const ll inf = 1e18;

ll a, b, l;

inline void solve() {
    cin >> a >> b >> l;
    ll res = 0;
    set<ll> ans;
    vector<ll> A, B;
    for (int i = 1; i <= l; i *= a)
        A.push_back(i);
    for (int i = 1; i <= l; i *= b)
        B.push_back(i);

    for (auto m : A) {
        for (auto n : B) {
            ll k = l / m / n;
            if (k * m * n == l) {
                ans.insert(k);
            }
        }
    }
    cout << ans.size() << endl;
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