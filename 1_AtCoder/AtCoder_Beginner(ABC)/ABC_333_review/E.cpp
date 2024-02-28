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

const int MAX_N = 200010;  // 定义最大数组长度
// 存储 每一类药水出现的位置：index 药水编号，val 是个vector，存的是出现位置
vector<int> pos[MAX_N];
// N为总事件数
// ty表示操作类型（1或2）：index 为事件编号，val 为事件类型（1或2）
// x为对应的药水编号或怪物编号：index 为事件编号，val 为 药水/怪物 种类编号
int N, ty[MAX_N], x[MAX_N];
// 用于标记此处的药水是否使用：
// index 为事件编号，val 为0或1（0表示该药水不用，1表示该药水使用）
int use[MAX_N];

int main() {
    cin >> N;  // 读取操作数量
    for (int i = 1; i <= N; i++) {
        cin >> ty[i] >> x[i];  // 读取每个操作的类型和值
        if (ty[i] == 1) {
            // 记录药水编号对应的位置
            pos[x[i]].push_back(i);
        } else {
            // 如果这个编号的药水没了，就输出 -1
            if (pos[x[i]].empty()) {
                cout
                    << "-1\n";  // 如果操作类型为2且x[i]之前没有出现过，则输出-1并结束程序
                return 0;
            }
            // 标记这个位置的药水为已使用
            use[pos[x[i]].back()] = 1;
            // 弹出这个药水的位置
            pos[x[i]].pop_back();
        }
    }

    int ma = 0;   // 记录最大持有药水数量
    int now = 0;  // 当前持有药水数量
    for (int i = 1; i <= N; i++) {
        // 如果这个位置的药水被用了
        if (use[i]) {
            now++;              // 持有药水数量 +1
            ma = max(ma, now);  // 更新最大持有药水数
        } else if (ty[i] == 2) {
            now--;  // 如果遇到怪物，持有药水数量 -1
        }
    }
    cout << ma << endl;  // 输出最大使用次数

    bool first_time = 1;  // 用于控制输出格式（是否是第一次输出）
    for (int i = 1; i <= N; i++) {
        // 要到药水时
        if (ty[i] == 1) {
            if (!first_time) {
                cout << ' ';  // 在非首次输出时，添加空格分隔
            } else {
                first_time = 0;  // 标记已经进行了首次输出
            }
            cout << use[i];  // 输出当前操作是否被使用（1或0）
        }
    }
    cout << endl;  // 输出结束，换行
}
