// Problem: https://www.acwing.com/problem/content/804/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 由于保存离散化的值，查询的l和r，最极端情况下有 30w 个值
const int N = 3e5 + 10;
int n, m;
vector<int> alls;
vector<PII> add, query;
int a[N], s[N];

// 在 alls 里面找到 x 的下标
int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

void solve() {
    // 放两个哨兵
    alls.push_back(-1e9);
    alls.push_back(1e9);

    cin >> n >> m;
    // 读入所有的增加值操作
    for (int i = 1; i <= n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    // 读入所有的查询操作
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l), alls.push_back(r);
    }

    // 排序，去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    // 处理所有的增加值操作
    for (auto item : add) {
        // 找到坐标在 alls 的 index
        // 因为 alls 里面有 -INF 占据0位置，所以找到的位置肯定是 大于等于1的
        int x = find(item.first);
        // 在 a 里面记录坐标对应值的变化（下标肯定是从1开始）
        a[x] += item.second;
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];

    // 输出结果
    for (auto item : query) {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}