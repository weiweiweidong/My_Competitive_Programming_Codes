// Problem: https://atcoder.jp/contests/abc390/tasks/abc390_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

char c;

void solve() {
    // 读入每个数字，并拼接成字符串
    string s;
    for (int i = 0; i < 5; i++) {
        cin >> c;
        s += c;
    }

    // 看一下，如果前后换一下位置，能不能凑成 12345
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        swap(s[i], s[i + 1]);
        if (s == "12345")
            flag = true;
        swap(s[i], s[i + 1]);
    }

    // 输出结果
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}