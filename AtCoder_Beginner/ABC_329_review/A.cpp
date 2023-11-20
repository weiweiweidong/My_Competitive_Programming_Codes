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
    string s;
    cin >> s;
    int n = s.size();
    string res;
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            res = res + s[i] + ' ';
        } else
            res += s[i];
    }
    cout << res << endl;
}