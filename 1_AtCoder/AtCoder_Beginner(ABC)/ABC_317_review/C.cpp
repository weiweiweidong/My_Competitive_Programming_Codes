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
    int N, M;
    cin >> N >> M;
    // 邻接矩阵，存储节点与节点之间的距离
    vector<vector<int>> dis(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        dis[A][B] = dis[B][A] = C;
    }
    // 包含 1～N 的所有节点
    vector<int> p;
    for (int i = 1; i <= N; i++) {
        p.push_back(i);
    }
    int ans = 0;
    // 遍历节点的所有可能的排列，看最长是多少
    do {
        int len_sum = 0;
        for (int i = 1; i < N; i++) {
            if (dis[p[i - 1]][p[i]] == 0)
                break;
            len_sum += dis[p[i - 1]][p[i]];
        }
        ans = max(ans, len_sum);
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;
}