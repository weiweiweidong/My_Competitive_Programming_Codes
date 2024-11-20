// Problem: https://www.acwing.com/problem/content/1120/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10;
int n;
int p[N];  // 储存所有数字
int group[N][N];
bool st[N];
int res = N;  // 最坏的情况下，每个元素单独一组

// 计算 a 与 b 的最大公约数
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

// 检查 p[i] 能否被添加到挡墙的 group 中。
// 如果 p[i] 与组内的任意数的 GCD 大于 1，返回 false
bool check(int group[], int gc, int i) {
    for (int j = 0; j < gc; j++)
        if (gcd(p[group[j]], p[i]) > 1)
            return false;
    return true;
}

// 第几组，当前组内下标，当前一共分了多少元素，从哪个下标开始搜
void dfs(int g, int gc, int tc, int start) {
    // 如果组的数量已经超出了目前的遍历过的最小值，就没必要继续看了，剪枝
    if (g >= res)
        return;
    // 如果元素已经被分完了，更新当前组数量
    if (tc == n)
        res = g;

    bool flag = true;  // 标记是否开新组
    // 遍历从 start 开始的所有未处理元素
    // （即：把能分配到当前组的数字全部加进这个组）
    for (int i = start; i < n; i++) {
        // 如果 i 还没有分配 && 可以被添加到 g 组
        if (!st[i] && check(group[g], gc, i)) {
            st[i] = true;
            group[g][gc] = i;
            // 当前组，组内元素数量+1，已被分配的元素数量+1，待分配元素光标移到下一个
            dfs(g, gc + 1, tc + 1, i + 1);
            st[i] = false;
            flag = true;
        }
    }

    // 如果 start 开始后面元素都没办法分配到当前组，就新开一个组
    // 这里有疑问，没看懂为什么要从 0 重新开始遍历？？？？？
    if (flag)
        dfs(g + 1, 0, tc, 0);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];

    // 从第一组开始搜，组内有0个元素，当前一共搜了0个元素，从0号下标开始搜
    dfs(1, 0, 0, 0);

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}