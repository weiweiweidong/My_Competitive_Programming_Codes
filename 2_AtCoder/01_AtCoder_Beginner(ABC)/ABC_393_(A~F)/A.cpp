// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string a, b;

void solve() {
    cin >> a >> b;
    if (a == "sick" && b == "fine")
        cout << 2 << endl;
    else if (a == "fine" && b == "sick")
        cout << 3 << endl;
    else if (a == "sick" && b == "sick")
        cout << 1 << endl;
    else
        cout << 4 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}