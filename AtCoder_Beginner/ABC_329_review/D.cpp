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

const int SIZE = 200010;

int main() {
    int n, m, x;
    cin >> n >> m;
    vector<int> votes(SIZE, 0);  // 记录每个人的得票数
    int maxVote = 0;             // 跟踪最大票数
    int king = n;                // 跟踪最大得票者
    for (int i = 0; i < m; i++) {
        cin >> x;    // 读入一张新选票
        votes[x]++;  // 该得票者值++
        // 如果该得票者的选票 >= 当前最高选票
        if (votes[x] >= maxVote) {
            if (votes[x] == maxVote) {
                king = min(king, x);  // 等于时，取编号小的那个
            } else {
                king = x;  // 否则，更新得票者编号
            }
            maxVote = votes[x];  // 更新最大票数
        }
        cout << king << endl;
    }
}