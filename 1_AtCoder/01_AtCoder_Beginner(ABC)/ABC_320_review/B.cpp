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

int main() {
    string S;
    cin >> S;
    int k = S.size();

    int res = 0;
    for (int i = 0; i < k; i++) {
        // 偶数情况下
        int m = i, n = i + 1;
        while (m >= 0 && n < k && S[m] == S[n])
            m--, n++;
        res = max(res, n - m - 1);
        // 奇数情况下
        m = i - 1, n = i + 1;
        while (m >= 0 && n < k && S[m] == S[n])
            m--, n++;
        res = max(res, n - m - 1);
    }
    cout << res << endl;
}
