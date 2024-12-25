// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

using Map = map<int, set<int>>;

Map mx, my;
vector<int> temp;
int n, m;  // 点的数量，移动次数
LL x, y;   // 起始坐标
LL res;
char d;  // 临时变量，记录移动方向
LL c;    // 临时变量，记录移动距离

//
void run(LL x, LL y, LL u, LL v, Map& i, Map& j) {
    // 判断点的位置是否合法
    if (!(!i[x].empty() && fabs(x) <= 1e9 && fabs(y) <= 1e9))
        return;

    temp.clear();

    auto bg = i[x].lower_bound(y + u);
    auto ed = i[x].upper_bound(y + v);

    // 从 bg 到 ed 之间所有的元素都要删除并计数
    for (auto it = bg; it != ed; it++) {
        res++;
        temp.push_back((*it));
    }

    // 在原始数组中删除经过的点
    for (auto p : temp) {
        i[x].erase(p);
        j[p].erase(x);
    }
}

void solve() {
    // 读入数据
    cin >> n >> m >> x >> y;
    for (int i = 1, u, v; i <= n; i++) {
        cin >> u >> v;
        mx[u].insert(v);  // x 下有多少个 y
        my[v].insert(u);  // y 下有多少个 x
    }
    // 处理所有移动
    for (int i = 1; i <= m; i++) {
        char d;
        cin >> d >> c;  // 读入移动方向和距离

        if (d == 'U')
            run(x, y, 0, c, mx, my), y += c;
        if (d == 'D')
            run(x, y, -c, 0, mx, my), y -= c;
        if (d == 'L')
            run(y, x, -c, 0, my, mx), x -= c;
        if (d == 'R')
            run(y, x, 0, c, my, mx), x += c;
    }

    cout << x << " " << y << " " << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}