// Problem: https://atcoder.jp/contests/abc302/tasks/abc302_c
// next_permutation 的使用
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 输出两个字符串有多少不同
int diff(string& a, string& b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            cnt++;
    }
    return cnt;
}

// 判断条件是否成立
bool check(vector<string>& g) {
    int n = g.size();
    for (int i = 1; i < n; i++) {
        // 俩俩判断是否只相差一个字母
        int res = diff(g[i - 1], g[i]);
        if (res != 1)
            return false;
    }
    return true;
}

void solve() {
    // 字符串有n个，字符串长度为m
    int n, m;
    cin >> n >> m;
    vector<string> g;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        g.push_back(s);
    }
    // 使用 next_permutation 前一定要先 sort！！！
    sort(g.begin(), g.end());

    bool flag = false;
    // 枚举每种可能性
    do {
        // 判断当前的g是否满足要求
        if (check(g)) {
            flag = true;
            break;
        }
    } while (next_permutation(g.begin(), g.end()));

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