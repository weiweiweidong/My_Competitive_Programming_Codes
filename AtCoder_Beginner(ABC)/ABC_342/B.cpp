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
    int N;
    cin >> N;
    vector<int> P(N + 1);
    unordered_map<int, int> h;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        h[P[i]] = i;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        if (h[a] < h[b])
            cout << a << endl;
        else
            cout << b << endl;
    }
}