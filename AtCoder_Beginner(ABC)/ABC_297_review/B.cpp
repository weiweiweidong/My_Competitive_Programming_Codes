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

string S;
unordered_map<char, vector<int>> h;

// 判断条件1：B的两个位置奇偶性不同
bool check1() {
    int a = h['B'][0] % 2, b = h['B'][1] % 2;
    return a ^ b;
}
// 判断条件2：K在两个R之间
bool check2() {
    int a = h['R'][0], b = h['R'][1];
    int z = h['K'][0];
    return z > a && z < b;
}

int main() {
    cin >> S;
    S = " " + S;

    for (int i = 1; i <= 8; i++)
        h[S[i]].push_back(i);

    if (check1() && check2())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}