// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a, b, c;

// 解法 1：分成四种情况来讨论
void solve1() {
    cin >> a >> b >> c;
    if (a + b == c || a + c == b || b + c == a || (a == b && b == c))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

// 解法 2：只要 sum 能被 abc 中的最大值整除即可
void solve2() {
    cin >> a >> b >> c;
    int mx = max({a, b, c});
    int sum = a + b + c;
    if (sum % mx == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve1();
    // solve2();
    return 0;
}