// Problem: https://atcoder.jp/contests/abc063/tasks/abc063_b

// 判断字符串中的字母是否都不相同
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

unordered_map<int, int> h;

void solve() {
    string S;
    cin >> S;
    for (auto c : S) {
        if (h.count(c - 'a')) {
            cout << "no" << endl;
            return;
        }
        h[c - 'a']++;
    }
    cout << "yes" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}