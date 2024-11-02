// Problem: https://atcoder.jp/contests/abc377/tasks/abc377_g
// 这是一道标准的 Trie 树模板题

/*
题目：
    给定 N 个字符串 S_i，只包含小写字母。
    另 T=S_k，进行下面两种操作之一
        操作 1：删除 T 最后一个字母，cost 为 1
        操作 2：给 T 最后添加一个字母，cost 为 1
    求将 T 变为空串 或 S_1 ~ S_{k-1} 中的任何一个串 所付出的最小代价

思路：
直观思路：先从 T 的尾部删除若干字符，删除后应该变成某个S_i的前缀，再开始添加字符
可以使用字典树
考虑对于 Trie 树上的每个节点，记录其到所有 S_i 的节点的最短距离 d。
这个距离等价于：从这个节点代表的字符串开始，至少添加多少个字符能够到达一个 S_i。
查询的时候，从T代表的节点不断向上爬，并统计（向上爬的步数+d）的最小值，就是答案

代码学习源：https://atcoder.jp/contests/abc377/submissions/59210482
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAX_N = 2e5 + 10;
int son[MAX_N][26], d[MAX_N], idx;
int n;
string s[MAX_N];

void insert(string s) {
    int p = 0;  // 从根节点开始。根节点的 idx 为 0
    // 更新根节点到某个字符串结尾的最短距离
    // 注：d 表示当前节点到某个字符串结尾的最短距离
    // 注：s.size() 是一个 unsigned 整数，在 min 里使用要 int 强制转换一下
    d[p] = min(d[p], (int)s.size());
    // 挨个遍历字符串的每个字符
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) {
            son[p][u] = ++idx;
            d[idx] = INT_MAX;
        }
        p = son[p][u];
        // 更新 d
        d[p] = min(d[p], (int)s.size() - i - 1);
    }
}

int query(string s) {
    int p = 0;
    int ans = s.size();
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u])
            break;
        p = son[p][u];
        // 统计答案
        ans = min(ans, (int)s.size() - i - 1 + d[p]);
    }
    return ans;
}

void solve() {
    cin >> n;
    d[0] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        int cur_ans = query(s[i]);
        insert(s[i]);
        cout << cur_ans << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}