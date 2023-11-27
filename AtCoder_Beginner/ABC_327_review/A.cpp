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
    int N;
    string S;
    cin >> N >> S;

    if (S.find("ab") != string::npos || S.find("ba") != string::npos)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}