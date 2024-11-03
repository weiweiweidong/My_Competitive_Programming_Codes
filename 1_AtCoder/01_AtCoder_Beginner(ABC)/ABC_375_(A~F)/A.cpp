// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int N;
    string S;
    cin >> N >> S;
    int res = 0;
    for (int i = 0; i < N - 2; i++)
        if (S[i] == '#' && S[i + 1] == '.' && S[i + 2] == '#')
            res++;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}