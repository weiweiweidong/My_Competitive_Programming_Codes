#include <math.h>
#include <string.h>
#include <algorithm>
#include <iomanip>
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

const int MAX_N = 300010;  // 最大节点数
int N;
vector<int> e[MAX_N];  // 用来存储邻接表
int num;

// x 表示当前要看哪个点
// lt 表示从哪个点来的
void dfs(int x, int lt) {
    // 每进来一次，操作数+1
    num++;
    for (int y : e[x]) {
        // 原路来的就不用管
        if (y == lt) {
            continue;
        }
        // 再向下走一级
        dfs(y, x);
    }
}
int main() {
    // 读取节点数，创建邻接表
    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    int ma = 0;
    // 开始遍历 1 节点的所有边
    for (int x : e[1]) {
        // 每遍历 1 延伸出去的一点，都先把 num 清零
        // 最终可以求出这条支路总共调用了多少次 dfs（即删掉了多少条边）
        num = 0;
        // 两个参数表示：x为当前要看哪个点，1表示从哪个点来的
        dfs(x, 1);
        // 求出来最多的一条支路，进行多少操作
        ma = max(ma, num);
    }
    // 最终答案就是 总节点数 - 最多的一条支路
    cout << N - ma << endl;
}