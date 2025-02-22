// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;
int res;

void solve() {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == 'B') {
                    for (int k = j + 1; k < s.size(); k++) {
                        if (s[k] == 'C' && k - j == j - i)
                            res++;
                    }
                }
            }
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