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
    cin >> N;
    string S;
    cin >> S;

    vector<int> t;
    int x;
    for (int i = 0; i < N; i++) {
        if (S[i] == '|')
            t.push_back(i);
        if (S[i] == '*')
            x = i;
    }

    if (x > t[0] && x < t[1])
        cout << "in" << endl;
    else
        cout << "out" << endl;
}