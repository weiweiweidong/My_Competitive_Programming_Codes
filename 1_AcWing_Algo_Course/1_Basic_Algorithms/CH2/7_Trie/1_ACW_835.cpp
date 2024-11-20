// Problem: https://www.acwing.com/problem/content/837/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int son[N][26], cnt[N], idx;
char str[N];
int n;

void insert(char* str) {
    // 给定根节点编号
    int p = 0;
    // 遍历str中的每一个字符
    for (int i = 0; str[i]; i++) {
        // 看字符对应的边
        int u = str[i] - 'a';
        // 如果是空节点，就创建一个节点
        if (!son[p][u])
            son[p][u] = ++idx;
        // 把子节点赋给p
        p = son[p][u];
    }
    // 结尾+1
    cnt[p]++;
}

int query(char* str) {
    // 给定父节点
    int p = 0;
    for (int i = 0; str[i]; i++) {
        // 获取边
        int u = str[i] - 'a';
        // 如果子节点为空，说明没有这个字符串，返回0
        if (!son[p][u])
            return 0;
        // 否则就把子节点赋给p
        p = son[p][u];
    }
    // 返回数量
    return cnt[p];
}

void solve() {
    cin >> n;
    while (n--) {
        char op[2];
        cin >> op >> str;
        if (*op == 'I')
            insert(str);
        else
            cout << query(str) << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}