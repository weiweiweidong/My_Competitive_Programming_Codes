// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    string s;
    cin >> s;
    int len = s.size();

    if (len % 2 != 0)
        cout << "No" << endl;
    else {
        s = "." + s;
        unordered_map<int, int> h;
        for (int i = 1; i <= len; i++)
            h[s[i] - 'a']++;

        for (int i = 1; i <= len / 2; i++) {
            if (s[2 * i] != s[2 * i - 1] || h[s[i] - 'a'] != 2) {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}