// Problem: https://atcoder.jp/contests/abc347/tasks/abc347_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int solve() {
    LL N, A, B;
    cin >> N >> A >> B;
    vector<LL> d;
    for (int i = 0; i < N; i++) {
        LL x;
        cin >> x;
        d.push_back(x % (A + B));
    }

    sort(d.begin(), d.end());
    d.push_back(d[0] + A + B);

    for (int i = 1; i < d.size(); i++) {
        if (d[i] - d[i - 1] > B) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}