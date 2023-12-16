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

#define int long long  // 将后续所有出现的 int 类型都定义为 long long
using namespace std;

const int MAX_N = 500010;
int N;
int A[MAX_N], P[MAX_N];
vector<int> e[MAX_N];
int depth[MAX_N];  // 存储节点的深度：index 节点编号；val 深度值
int s[MAX_N];  // 存储深度每一层的 总和：index 深度；val 当前深度层的值的和

void dfs(int x) {
    s[depth[x]] += A[x];
    for (auto i : e[x]) {
        depth[i] = depth[x] + 1;
        dfs(i);
    }
}

signed main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 2; i <= N; i++) {
        cin >> P[i];
        e[P[i]].push_back(i);
    }

    dfs(1);

    // 因为1节点的深度没有设置的，所以为0：depth[1]==0
    for (int i = N; i > 0; i--) {
        if (s[i] > 0) {
            cout << "+" << endl;
            return 0;
        } else if (s[i] < 0) {
            cout << "-" << endl;
            return 0;
        }
    }
    cout << "0" << endl;
    return 0;
}
