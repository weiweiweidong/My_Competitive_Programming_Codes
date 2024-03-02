#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

bool check(LL x) {
    string s = to_string(x);

    int i = 0;
    while (s[i] == '0')
        i++;
    s = s.substr(i);
    string t = s;
    reverse(s.begin(), s.end());
    if (s == t)
        return true;
    return false;
}

int main() {
    LL N;
    cin >> N;
    LL res = 1;
    for (LL i = 1; i * i <= N / i; i++) {
        LL tmp = i * i * i;
        if (check(tmp))
            res = max(res, tmp);
    }

    cout << res << endl;
}