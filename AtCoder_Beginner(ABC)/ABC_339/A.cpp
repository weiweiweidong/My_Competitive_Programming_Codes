#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    string S;
    cin >> S;
    int n = S.size();

    while (n >= 0 && S[n] != '.')
        n--;

    cout << S.substr(n + 1) << endl;
}