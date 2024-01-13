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

int main() {
    int N, D, P;
    cin >> N >> D >> P;
    // 读入每天的交通费并排序
    vector<LL> F(N, 0);
    for (int i = 0; i < N; i++)
        cin >> F[i];
    sort(F.begin(), F.end(), greater<int>());

    // t 表示遍历第几个D
    int t = 0;
    // i 表示F的index
    int i = 0;
    LL res = 0;

    // 开始遍历
    while (i < N) {
        // 起点
        i = t * D;
        // 计算这D天的交通支出
        LL F_cost = 0;
        while (i < N && i / D == t) {
            F_cost += F[i];
            i++;
        }
        if (F_cost < P)
            res += F_cost;
        else
            res += P;
        t++;
    }
    cout << res << endl;
}