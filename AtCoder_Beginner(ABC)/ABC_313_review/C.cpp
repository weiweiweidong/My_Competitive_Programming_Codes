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
    int n;
    cin >> n;
    vector<LL> A(n);
    LL sum = 0;
    // 把数组存储起来，并且求一下总和
    for (LL& x : A) {
        cin >> x;
        sum += x;
    }
    // 降序排列
    sort(A.begin(), A.end(), greater<int>());
    // 求平均数a 和 余数b
    LL a = sum / A.size();
    LL b = sum % A.size();
    // 预处理最终结果，并且把余数摊到前面
    vector<LL> B(n, a);
    for (int i = 0; i < b; i++) {
        B[i]++;
    }

    LL res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(A[i] - B[i]);
    }
    cout << res / 2 << endl;
}