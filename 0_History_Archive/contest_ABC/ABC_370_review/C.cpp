// Problem:

// （贪心）最小化字典序：
// 先从前往后：如果字典序能降低，从前往后优先改动
// 再从后往前：如果字典序会增大，从后往前优先改动

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string S, T;

void solve() {
    cin >> S >> T;
    int n = S.size();
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        if (S[i] > T[i]) {
            S[i] = T[i];
            ans.push_back(S);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (S[i] < T[i]) {
            S[i] = T[i];
            ans.push_back(S);
        }
    }

    if (S == T) {
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}