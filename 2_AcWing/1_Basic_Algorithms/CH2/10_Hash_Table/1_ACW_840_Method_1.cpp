// Problem: https://www.acwing.com/problem/content/842/
// 拉链法模拟哈希表
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 1e5 后的第一个质数
const int N = 1e5 + 3;
int h[N], ne[N], e[N], idx;
int n;

// 将x插入哈希表
void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx;
    idx++;
}
// 查询哈希表中是否存在x
bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x)
            return true;
    }
    return false;
}

void solve() {
    cin >> n;
    // h初始化
    memset(h, -1, sizeof h);
    while (n--) {
        char op[2];
        int x;
        cin >> op >> x;
        if (*op == 'I')
            insert(x);
        else {
            if (find(x))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}