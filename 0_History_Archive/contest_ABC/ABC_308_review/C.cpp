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

struct tt {
    LL a;
    LL b;
    int index;
};

bool cmp(tt& A, tt& B) {
    LL arate = A.a * (B.a + B.b);
    LL brate = B.a * (A.a + A.b);

    if (arate == brate)
        return A.index < B.index;
    else
        return arate > brate;
}

int main() {
    int n;
    cin >> n;
    vector<tt> p(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        p[i].a = a;
        p[i].b = b;
        p[i].index = i;
    }

    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << p[i].index + 1;
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
}