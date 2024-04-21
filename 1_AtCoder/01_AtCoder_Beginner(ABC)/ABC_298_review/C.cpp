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
    int N, Q;
    cin >> N >> Q;
    unordered_map<int, multiset<int>> box;
    unordered_map<int, set<int>> card;

    for (int i = 1; i <= Q; i++) {
        int op, x, y;
        cin >> op;
        // 存入操作
        if (op == 1) {
            cin >> x >> y;
            box[y].insert(x);
            card[x].insert(y);
        }
        // 输出x号盒子的所有卡
        else if (op == 2) {
            cin >> x;
            auto s = box[x];
            for (auto it = s.begin(); it != s.end(); it++)
                cout << (*it) << " ";
            cout << endl;
        }
        // 输出x号卡对应的所有盒子
        else {
            cin >> x;
            auto s = card[x];
            for (auto it = s.begin(); it != s.end(); it++)
                cout << (*it) << " ";
            cout << endl;
        }
    }
}