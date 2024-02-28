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

long long W[16];
int N, D;
long long sum;         // 存储所有物品的总重量
long long res = 8e18;  // 存储最小方差。初始化为一个很大的数字
long long bag[16];     // 存储每个背包中的权重和

// 返回 x 的平方
double sqr(double x) {
    return x * x;
}

// x 表示当前要处理的权重索引
// num 表示当前已经使用的背包数量
// EX2 是当前分配方案的平方和
void dfs(int x, int num, long long EX2) {
    // 终止条件
    if (x > N) {
        // 更新一下 res 的值
        res = min(res, EX2);
        return;
    }

    // 确定当前的物品放在哪个背包里面，范围就是 [st,n]。
    // 限制范围是为了避免重复搜索

    // 确定背包编号的终点
    int n = min(num + 1, D);
    // 确定背包编号的起点
    int st = 1;

    // 剩余未处理的权重数量 等于 剩余背包的数量 的时候，
    // 就默认把剩余的权重分别放在剩余每个空背包中
    // 这两行代码可以避免无效的搜索，优化了DFS的效率
    if (N - x + 1 == D - num) {
        st = num + 1;
    }

    // 遍历每个可能的背包，并把当前权重 W[x] 放进去
    for (int i = st; i <= n; i++) {
        // 计算新的平方和
        long long new_EX2 = EX2 + W[x] * W[x] + 2 * W[x] * bag[i];
        // 在第i个背包添加 x 物品
        bag[i] += W[x];
        // 搜下一个物品
        dfs(x + 1, max(num, i), new_EX2);
        // 恢复原样
        bag[i] -= W[x];
    }
}

int main() {
    cin >> N >> D;
    for (int i = 1; i <= N; i++) {
        cin >> W[i];
        sum += W[i];  // 求一下总重量
    }

    dfs(1, 0, 0);

    // 输出保留12位小数
    cout << fixed << setprecision(12) << (res * D - sum * sum) * 1. / (D * D)
         << endl;
}