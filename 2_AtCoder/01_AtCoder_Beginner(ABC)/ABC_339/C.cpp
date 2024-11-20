#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int N;
    cin >> N;

    vector<int> A(N + 1), s(N + 1);
    int A_min = 1e18;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        s[i] = s[i - 1] + A[i];
        A_min = min(A_min, s[i]);
    }

    if (A_min >= 0)
        cout << s[N] << endl;
    else
        cout << -A_min + s[N] << endl;
}