// Problem: https://atcoder.jp/contests/abc347/tasks/abc347_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int N, K;

void solve() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        if (x % K == 0)
            cout << x / K << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}