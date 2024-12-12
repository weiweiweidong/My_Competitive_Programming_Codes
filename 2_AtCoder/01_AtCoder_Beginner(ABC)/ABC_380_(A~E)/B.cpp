// Problem: https://atcoder.jp/contests/abc380/tasks/abc380_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 双指针做法
void solve1() {
    string s;
    cin >> s;

    vector<int> res;
    int last = 0;
    for (int i = 1; i < s.size(); i++) {
        int j = i;
        while (j < s.size() && s[j] != '|')
            j++;
        res.push_back(j - last - 1);
        i = j;
        last = j;
    }

    for (auto x : res)
        cout << x << " ";
    cout << endl;
}

// 推荐写法：更具有编程思维
void solve2() {
    string s;
    cin >> s;

    vector<int> res;
    int now = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '|')
            res.push_back(now), now = 0;
        else
            now++;
    }

    for (int i = 1; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // solve1();
    solve2();
    return 0;
}