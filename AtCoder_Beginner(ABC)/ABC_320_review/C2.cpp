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

const int INF = 1e9;
int main() {
    int M, ans = INF;
    cin >> M;
    string S[3];
    for (int i = 0; i < 3; i++)
        cin >> S[i];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                if (S[0][i] != S[1][j] || S[0][i] != S[2][k])
                    continue;
                // 如果当三个字符都相同时，保存位置 ijk 到一个数组t里面
                int t[3]{i, j, k};
                // 如果位置有相同，就加上M（即下一轮才拍按钮）
                if (t[1] == t[0])
                    t[1] += M;
                if (t[2] == t[0])
                    t[2] += M;
                if (t[2] == t[1])
                    t[2] += M;
                ans = min(ans, max({t[0], t[1], t[2]}));
            }
        }
    }
    if (ans == INF)
        ans = -1;
    cout << ans << '\n';
}