#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
LL score[N];

int main() {
    int n, t;
    cin >> n >> t;
    unordered_map<LL, int> h;
    h[0ll] = n;
    set<LL> uni;
    uni.insert(0);

    for (int i = 1; i <= t; i++) {
        int a, b;
        cin >> a >> b;
        // 1. 之前的数字出现次数-1；如果清空了的话，set里这个数字清掉
        LL ori = score[a];
        h[ori]--;
        if (h[ori] == 0) {
            auto it = uni.find(ori);
            uni.erase(*it);
        }

        // 2. 新的数字出现次数+1；如果是第一次出现，要在set里加入这个数字；
        score[a] += b;
        LL now = score[a];
        h[now]++;
        if (h[now] == 1) {
            uni.insert(now);
        }

        cout << uni.size() << endl;
    }
}