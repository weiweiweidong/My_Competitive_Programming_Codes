// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;
int n;

void solve() {
    cin >> n >> s;

    int res = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '/') {
            int j = 1;
            while (i - j >= 0 && i + j < n && s[i - j] == '1' &&
                   s[i + j] == '2')
                j++;
            res = max(res, 2 * j - 1);
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}