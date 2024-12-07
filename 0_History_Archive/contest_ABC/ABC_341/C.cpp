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
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

// 返回方向
int direction(char s) {
    if (s == 'R')
        return 0;
    else if (s == 'D')
        return 1;
    else if (s == 'L')
        return 2;
    else if (s == 'U')
        return 3;
    return 0;
}

// 判断是否能走通
bool check(int x, int y, vector<string>& S, string& T) {
    if (S[x][y] != '.')
        return false;

    int n = T.size();
    for (auto& t : T) {
        int dir = direction(t);
        int a = x + dx[dir], b = y + dy[dir];
        if (a < 0 || a >= S.size() || b < 0 || b > S[0].size())
            return false;
        if (S[a][b] != '.')
            return false;
        x = a, y = b;
    }
    return true;
}

int main() {
    int H, W, N;
    string T;
    cin >> H >> W >> N >> T;
    vector<string> S(H);
    for (int i = 0; i < H; i++)
        cin >> S[i];

    int res = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (check(i, j, S, T))
                res++;
        }
    }
    cout << res << endl;
}