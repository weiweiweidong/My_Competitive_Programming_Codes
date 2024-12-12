// Problem: https://atcoder.jp/contests/abc380/tasks/abc380_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 无脑写法
void solve1() {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (auto x : s) {
        if (x == '1')
            a++;
        if (x == '2')
            b++;
        if (x == '3')
            c++;
    }

    if (a == 1 && b == 2 && c == 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

// 推荐写法：
void solve2() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cout << (s == "122333" ? "Yes" : "No") << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // solve1();  // 解法 1
    solve2();  // 解法 2
    return 0;
}