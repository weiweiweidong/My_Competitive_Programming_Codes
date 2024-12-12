// Problem: https://atcoder.jp/contests/abc380/tasks/abc380_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 解法 1：使用字符串拼接
void solve1() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string res;

    int last_start = 0, last_ed = 0;
    int start = 0, ed = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        int j = i;
        // 找第一次 1 出现的起点
        while (j < s.size() && s[j] != '1')
            j++;
        start = j;

        // 找 1 出现的终点
        while (j < s.size() && s[j] == '1')
            j++;
        ed = j - 1;

        if (cnt == 0) {
            last_start = start, last_ed = ed;
        }

        cnt++;

        if (cnt == k) {
            res = s.substr(0, last_ed + 1) + s.substr(start, ed - start + 1) +
                  s.substr(last_ed + 1, start - last_ed - 1) + s.substr(ed + 1);
            break;
        }
        i = j - 1;
        if (cnt > 1) {
            last_start = start, last_ed = ed;
        }
    }

    cout << res << endl;
}

// 解法 2：
void solve2() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    s += ".";  // 技巧：防止越界，保证最后一段也被记录
    vector<PII> v;
    int now = s[0], num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == now)
            num++;  // 计算段内长度
        else {
            v.push_back({now - '0', num});  // 记录这一段的数据:{符号，长度}
            now = s[i], num = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        // 找到第 k 段为 1 的位置
        if (v[i].first == 1) {
            cnt++;
            if (cnt == k)
                // 交换位置
                swap(v[i], v[i - 1]);
        }
    }

    // 重新输出
    for (auto x : v) {
        for (int i = 0; i < x.second; i++)
            cout << x.first;
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // solve1();
    solve2();
    return 0;
}