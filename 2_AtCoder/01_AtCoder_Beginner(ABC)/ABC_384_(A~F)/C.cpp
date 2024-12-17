// Problem: https://atcoder.jp/contests/abc384/tasks/abc384_c

// 位运算
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a[5];

struct Score {
    int s;       // 存储分值
    int st;      // 存储二进制状态
    string str;  // 存储对应的做题方案
} s[50];

// 自定义算子
bool cmp(const Score& a, const Score& b) {
    if (a.s != b.s) {
        return a.s > b.s;  // s 不同时按 s 降序
    }
    return a.str < b.str;  // s 相同时按 str 字典序升序
}

// 也可以写成重载小于号的形式
// bool operator<(const Score& a, const Score& b) {
//     if (a.s != b.s)
//         return a.s > b.s;
//     return a.str < b.str;
// }

// 将二进制状态转化为字符串
string make_str(int x) {
    string s = "";
    for (int i = 0; i < 5; i++)
        if (x >> i & 1)
            s += "ABCDE"[i];
    sort(s.begin(), s.end());
    return s;
}

// 计算当前二进制状态的分值
int cal_score(int x) {
    int res = 0;
    for (int i = 0; i < 5; i++)
        if (x >> i & 1)
            res += a[i];
    return res;
}

void solve() {
    // 读入各个题目的分值
    for (int i = 0; i < 5; i++)
        cin >> a[i];

    // 遍历所有 32 种状态，同时计算 分值 和 对应的字符串
    for (int i = 0; i <= 31; i++) {
        s[i].st = i;
        s[i].s = cal_score(i);
        s[i].str = make_str(i);
    }

    // 排序
    sort(s, s + 32, cmp);

    // 输出结果（只输出前 31 个结果，第 32 个结果是空集，跳过）
    for (int i = 0; i < 31; i++)
        cout << s[i].str << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}