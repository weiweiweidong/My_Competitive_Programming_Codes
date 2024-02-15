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
    string S;
    cin >> S;
    vector<int> h(26);

    int res = 0;
    for (int i = 0; i < S.size(); i++) {
        h[S[i] - 'a']++;
        res = max(res, h[S[i] - 'a']);
    }

    for (int i = 0; i < 26; i++) {
        if (h[i] == res) {
            cout << char('a' + i) << endl;
            return 0;
        }
    }
}