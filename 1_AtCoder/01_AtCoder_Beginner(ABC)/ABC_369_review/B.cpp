// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;

void solve() {
    int n;
    cin >> n;
    int l_res = 0, r_res = 0;
    int l_last = -1, r_last = -1;

    while (n--) {
        int pos;
        char hand;
        cin >> pos >> hand;
        if (hand == 'L') {
            if (l_last == -1)
                l_last = pos;
            else {
                l_res += abs(l_last - pos);
                l_last = pos;
            }

        } else if (hand == 'R') {
            if (r_last == -1)
                r_last = pos;
            else {
                r_res += abs(r_last - pos);
                r_last = pos;
            }
        }
    }
    cout << l_res + r_res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}