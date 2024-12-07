// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1, 0);
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] != i)
            mp[A[i]] = i;
    }

    vector<PII> actions;
    for (int i = 1; i <= n; i++) {
        if (A[i] != i) {
            mp[A[i]] = mp[i];
            swap(A[i], A[mp[i]]);
            actions.push_back({i, mp[i]});
        }
    }

    cout << actions.size() << endl;
    for (auto x : actions) {
        cout << x.first << " " << x.second << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}