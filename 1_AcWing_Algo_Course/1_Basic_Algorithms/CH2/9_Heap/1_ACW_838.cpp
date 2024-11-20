// Problem: https://www.acwing.com/problem/content/840/
// 用数组实现一个小根堆，实现堆排序
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m;
int heap[N], cnt;

void down(int u) {
    int t = u;
    if (u * 2 <= cnt && heap[u * 2] < heap[t])
        t = u * 2;
    if (u * 2 + 1 <= cnt && heap[u * 2 + 1] < heap[t])
        t = u * 2 + 1;
    if (u != t) {
        swap(heap[u], heap[t]);
        down(t);
    }
}
void up(int u) {
    while (u / 2 && heap[u / 2] > heap[u]) {
        swap(heap[u / 2], heap[u]);
        u /= 2;
    }
}

void solve() {
    // 读入所有数据
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> heap[i];
    cnt = n;

    // 堆初始化，O(n) 复杂度
    for (int i = n / 2; i; i--)
        down(i);

    // 输出前m个小的值。O(mlogn) 复杂度
    while (m--) {
        cout << heap[1] << " ";
        heap[1] = heap[cnt];
        cnt--;
        down(1);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}