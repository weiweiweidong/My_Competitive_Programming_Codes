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
    int N;
    string S;
    cin >> N >> S;
    unordered_map<char, int> h;
    for (char& x : S)
        h[x]++;

    if (h.count('o') && h['o'] > 0 && !h.count('x'))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}