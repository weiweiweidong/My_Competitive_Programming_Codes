// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
LL cnt[26], sum[26];
string s;
LL res;

void solve() {
    // 读入数据
    cin >> s;

    for (LL i = 0; i < s.size(); i++) {
        LL c = s[i] - 'A';
        res += (i - 1) * cnt[c] - sum[c];
        cnt[c]++;
        sum[c] += i;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}