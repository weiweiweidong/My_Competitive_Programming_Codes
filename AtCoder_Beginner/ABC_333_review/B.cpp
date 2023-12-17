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
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    set<string> A{"AB", "BC", "CD", "DE", "AE"};
    set<string> B{"AC", "AD", "BD", "BE", "CE"};

    if (A.count(a) && A.count(b) || B.count(a) && B.count(b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}