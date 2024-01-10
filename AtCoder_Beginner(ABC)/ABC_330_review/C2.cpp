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

const LL MAX_V = 2000000000000;
int main() {
    vector<LL> nums{0};
    LL val = 1;
    while (nums.back() <= 2e12) {
        nums.push_back(val * val);
        val++;
    }

    LL D;
    cin >> D;
    LL res = 2e12 + 10;
    for (LL x : nums) {
        auto it = lower_bound(nums.begin(), nums.end(), D - x);
        if (it != nums.end()) {
            res = min(res, abs(*it + x - D));
        }
        if (it != nums.begin()) {
            it--;
            res = min(res, abs(*it + x - D));
        }
    }
    cout << res << endl;
}