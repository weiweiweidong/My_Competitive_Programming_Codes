// Problem: https://atcoder.jp/contests/abc303/tasks/abc303_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

unordered_map<int, set<int>> mp;
int n, h, m, k;
string s;

void solve() {
    // 读入数据
    cin >> n >> m >> h >> k;
    cin >> s;
    while (m--) {
        int x, y;
        cin >> x >> y;
        mp[x].insert(y);
    }

    // 初始化
    bool is_survival = true;
    int x = 0, y = 0, hp = h;
    for (auto c : s) {
        // 移动到下一点，并减少一点血
        if (c == 'R')
            x++;
        else if (c == 'L')
            x--;
        else if (c == 'U')
            y++;
        else if (c == 'D')
            y--;
        hp--;
        // 如果血没了
        if (hp < 0) {
            is_survival = false;
            break;
        }
        // 查找一下有没有血包
        if (mp.count(x) && mp[x].find(y) != mp[x].end() && hp < k) {
            hp = k;
            mp[x].erase(mp[x].find(y));
        }
    }

    // 输出结果
    if (is_survival)
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