#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long L;
typedef long long LL;
using namespace std;

#include <type_traits>

int main() {
    int n;
    string s;
    cin >> n >> s;
    int cnt[30] = {};

    int i = 0;
    while (i < n) {
        int j = i;
        while (s[i] == s[j]) {
            j++;
        }
        cnt[s[i] - 'a'] = max(cnt[s[i] - 'a'], j - i);
        i = j;
    }
    int ans = 0;
    for (int i = 0; i < 30; i++) {
        ans += cnt[i];
    }
    cout << ans << endl;
}
