// Problem: https://www.acwing.com/problem/content/842/
// 开放寻址法模拟哈希表
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

/*
    1. 开放寻址法会开 2～3 倍空间（本题操作数是1e5，这里开了2倍）
    2. 找到第一个质数（这里用 2e5+3 ）
*/
const int N = 2e5 + 3;
const int null = 0x3f3f3f3f;
int h[N], n;

/*
    核心代码find:
    1. 如果能找到x，返回的就是x在哈希表中的下标
    2. 如果不能找到x，返回的是x应该所在的空位置的下标
*/
int find(int x) {
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) {
        k++;
        if (k == N)
            k = 0;
    }
    return k;
}

void solve() {
    memset(h, 0x3f, sizeof h);
    cin >> n;
    while (n--) {
        char op[2];
        int x;
        cin >> op >> x;
        if (*op == 'I')
            h[find(x)] = x;
        else if (*op == 'Q') {
            if (h[find(x)] == null)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}