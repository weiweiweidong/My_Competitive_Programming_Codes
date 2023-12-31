// https://atcoder.jp/contests/abc208/tasks/abc208_b

#include <iostream>
#include <vector>
using namespace std;

int P;
vector<int> coins;

int main() {
    cin >> P;

    int coin = 1;
    for (int i = 1; i <= 10; i++) {
        coin *= i;
        coins.push_back(coin);
    }

    int res = 0;
    for (int i = 9; i >= 0; i--) {
        res += P / coins[i];
        P %= coins[i];
    }
    cout << res << endl;
}
