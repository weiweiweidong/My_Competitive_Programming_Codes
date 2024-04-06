// Problem: https://atcoder.jp/contests/abc347/tasks/abc347_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

unordered_set<string> hp;
string S;

void solve() {
    cin >> S;

    // 枚举起点
    for (int i = 0; i < S.size(); i++) {
        // 枚举终点
        for (int j = i; j < S.size(); j++) {
            // 抽取子串
            hp.insert(S.substr(i, j - i + 1));
        }
    }

    // 输出子串的数量
    cout << hp.size() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}