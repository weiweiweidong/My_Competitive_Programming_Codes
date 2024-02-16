#include <math.h>
#include <algorithm>
#include <cstring>
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
    int n, m;
    cin >> n >> m;
    vector<int> in(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // 一条从a指向b的边，记录b的入度
        in[b]++;
    }

    // cnt：入度为0的点有多少个；poi：入度为0的点的编号
    int cnt = 0, poi = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            cnt++, poi = i;
    }

    // 如果只有1个点入度为0，说明它最大
    if (cnt == 1)
        cout << poi << endl;
    else
        cout << "-1" << endl;
}