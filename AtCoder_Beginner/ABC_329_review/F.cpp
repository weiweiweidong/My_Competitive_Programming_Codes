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

// 本题目涉及颜色去重复，很容易就联想到使用 set 来解决
const int MAX_N = 200010;
set<int> C[MAX_N];  // 记录每个箱子里有哪些颜色的球

int main() {
    int N, Q;
    cin >> N >> Q;
    // 读入每个箱子里装的什么颜色的球
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        C[i].insert(x);
    }

    while (Q--) {
        int a, b;
        cin >> a >> b;

        // 优化项： 如果 a set 的尺寸大于 b set，就把它们交换。
        // （保证用尺寸小的插入尺寸大的）
        if (C[a].size() > C[b].size())
            C[a].swap(C[b]);

        // 把 a set 的元素全部插入 b set中
        C[b].insert(C[a].begin(), C[a].end());
        // 把 a 清空
        C[a].clear();
        // 输出 b 的大小
        cout << C[b].size() << endl;
    }
}
