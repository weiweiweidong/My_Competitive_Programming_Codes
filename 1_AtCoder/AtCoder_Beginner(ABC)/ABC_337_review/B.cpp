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

    vector<int> x(3);
    for (int i = 0; i < S.size(); i++) {
        x[S[i] - 'A']++;
    }

    string res = "";
    res += string(x[0], 'A');
    res += string(x[1], 'B');
    res += string(x[2], 'C');

    if (res == S)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}