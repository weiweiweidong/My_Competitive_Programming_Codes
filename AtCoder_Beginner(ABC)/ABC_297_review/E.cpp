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
    int N, K;
    cin >> N >> K;
    set<LL> Q;
    vector<LL> A(N);
    // 保存数组，同时把值插入set中
    for (LL& x : A) {
        cin >> x;
        Q.insert(x);
    }

    // 遍历K-1次，分别计算出前K-1个最小值，并清除
    for (int i = 0; i < K - 1; i++) {
        LL me = *Q.begin();
        Q.erase(me);
        // 将新的值放入set中。set是由红黑树实现的，各种操作平均时间复杂度为
        // O(logn)
        for (auto x : A) {
            Q.insert(me + x);
        }
    }
    // 此时Q的最小值就是要求的第K小的值
    cout << *Q.begin() << endl;
}