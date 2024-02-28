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
using namespace std;

typedef long L;
typedef long long LL;
typedef pair<int, int> PII;

int main() {
    string S;
    cin >> S;
    unordered_map<char, int> h;
    for (auto x : S)
        h[x]++;

    for (int i = 0; i < S.size(); i++) {
        if (h[S[i]] == 1) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}