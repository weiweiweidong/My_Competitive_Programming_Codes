// Problem: https://atcoder.jp/contests/abc386/tasks/abc386_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s, t;
int k;

void solve() {
    // 读入数据
    cin >> k >> s >> t;

    // 如果 s 和 t 完全相同
    if (s == t) {
        cout << "Yes" << endl;
        return;
    }

    // 情况 1：如果长度相同
    if (s.size() == t.size()) {
        int x, y;
        // 从前到后，找到最后一个差异点位置
        for (int i = 0; i < s.size(); i++)
            if (s[i] != t[i])
                x = i;
        // 从后往前，找到第一个差异点位置
        for (int i = s.size() - 1; i >= 0; i--)
            if (s[i] != t[i])
                y = i;
        // 如果位置相同，说明只有一个点不同
        if (x == y)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return;
    }

    // 如果长度不同，让 s 是长的那个
    if (s.size() < t.size())
        swap(s, t);

    // 如果长度差异为 1
    if (s.size() - t.size() == 1) {
        int x;
        // 找到第一个差异点
        for (int i = 0; i < s.size(); i++)
            if (s[i] != t[i]) {
                x = i;
                break;
            }

        // 跳过这一个差异点，把前面和后面拼接起来
        string tmp = s.substr(0, x) + s.substr(x + 1);

        // 如果拼接后的字符串 tmp 和 t 相同，说明只有一个差异点
        if (tmp == t)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return;
    }

    // 如果能走到这一步，说明长度差异大于 2
    cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}