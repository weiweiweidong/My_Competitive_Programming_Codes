#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long L;
typedef long long LL;
using namespace std;

const int MAX_SIZE = 100010;

int main() {
    set<pair<int, int>> ban;
    int N, M, L;
    cin >> N >> M >> L;
    // 主菜价格 和 副菜价格
    int a[MAX_SIZE], b[MAX_SIZE];
    // da 和 db 用于对价格排序，同时保留原始位置
    vector<pair<int, int>> da, db;
    // 读入a数据
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        da.push_back({a[i], i});
    }
    // 读入b数据
    for (int i = 1; i <= M; i++) {
        cin >> b[i];
        db.push_back({b[i], i});
    }
    // 读入禁止的搭配，内容为 { a的index ， b的index }
    while (L--) {
        int c, d;
        cin >> c >> d;
        ban.insert({c, d});
    }
    // 对价格排序
    sort(da.begin(), da.end());
    sort(db.begin(), db.end());

    // 如果 主菜最大 和 副菜最大 的搭配没有被禁，就直接返回答案
    if (ban.find(make_pair(da.back().second, db.back().second)) == ban.end()) {
        cout << da.back().first + db.back().first << endl;
        return 0;
    }
    // 否则，通过遍历来找答案
    int ans = 0;
    // 对于 ban 中的每一对
    for (auto& [c, d] : ban) {
        // 找 c 的位置
        auto pos_c =
            lower_bound(da.begin(), da.end(), make_pair(a[c], c)) - da.begin();
        // 找 d 的位置
        auto pos_d =
            lower_bound(db.begin(), db.end(), make_pair(b[d], d)) - db.begin();
        // 检查被禁止的 c 周围
        if (pos_c &&
            // 看 pos_c-1 和 d 是否被禁。如果没有，算一下最值
            ban.find(make_pair(da[pos_c - 1].second, d)) == ban.end()) {
            ans = max(ans, da[pos_c - 1].first + b[d]);
        }
        if (pos_d &&
            // 看 c 和 pos_d-1 是否被禁。如果没有，算一下最值
            ban.find(make_pair(c, db[pos_d - 1].second)) == ban.end()) {
            ans = max(ans, a[c] + db[pos_d - 1].first);
        }
    }
    cout << ans << '\n';
}