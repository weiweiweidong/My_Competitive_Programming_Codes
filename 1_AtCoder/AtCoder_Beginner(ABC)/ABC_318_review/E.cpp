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

LL cal(vector<int>& v) {
    int n = v.size();
    if (n <= 1)
        return 0;
    LL res = 0;
    LL sum = 0;
    // 计算S：从数列中三元组，第一个和第三个数相同的取法
    for (LL i = 0; i < n; i++) {
        res += v[i] * i - sum - i;
        sum += v[i];
    }
    // 计算T：从数列中三元组，三个数全部相同的取法。（从n个中取3个。使用了C{_n}{^3}的计算公式）
    res -= n * (n - 1LL) * (n - 2) / 6;
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<LL> A(N + 1);
    unordered_map<LL, vector<int>> hash;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        hash[A[i]].push_back(i);
    }

    LL res = 0;
    for (auto [k, v] : hash) {
        res += cal(v);
    }

    cout << res << endl;
}