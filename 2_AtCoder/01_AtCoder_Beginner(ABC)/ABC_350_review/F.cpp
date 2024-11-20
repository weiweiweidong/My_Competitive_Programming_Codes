// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

char flp(char x) {
    if (x >= 'A' && x <= 'Z')
        return (x - 'A' + 'a');
    return (x - 'a' + 'A');
}

string s;
vector<int> mch;

void f(int l, int r, int d) {
    // 正序输出
    if (d == 0) {
        while (l <= r) {
            if (s[l] == '(') {
                f(l + 1, mch[l] - 1, 1);
                l = mch[l];
            } else {
                cout << s[l];
            }
            l++;
        }
    }
    // 反序输出
    else {
        while (l <= r) {
            if (s[r] == ')') {
                f(mch[r] + 1, r - 1, 0);
                r = mch[r];
            } else {
                cout << s[r];
            }
            r--;
        }
    }
}

void solve() {
    cin >> s;
    int len = s.size();
    mch = vector<int>(len, -1);

    int h = 0;
    vector<int> stk;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            stk.push_back(i);
            h++;
        } else if (s[i] == ')') {
            mch[i] = stk.back();
            mch[stk.back()] = i;
            stk.pop_back();
            h--;
        } else if (h % 2 == 1) {
            s[i] = flp(s[i]);
        }
    }

    f(0, len - 1, 0);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}