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

const int SIZE = 4;
const int ROTATE_NUM = 4;
const int TILE_NUM = 3;

// 顺时针旋转90度
void rotate(string s[]) {
    char tmp[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tmp[j][SIZE - 1 - i] = s[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++) {
        s[i] = string(tmp[i], tmp[i] + SIZE);
    }
}
// 判断坐标是否在4*4方块内
bool valid(int x) {
    return x >= 0 && x < SIZE;
}
// 对于给定的拼图块和移动量，计算拼图块覆盖方格的位表示。
// 返回 -1 表示拼图块超出了方块范围
int get(string s[], int dx, int dy) {
    int ret = 0;
    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            if (s[x][y] == '#') {
                int real_x = x + dx;
                int real_y = y + dy;
                if (!valid(real_x) || !valid(real_y)) {
                    return -1;
                }
                ret |= 1 << (real_x * 4 + real_y);
            }
        }
    }
    return ret;
}

// 读取拼图块，并生成该拼图块的所有可能状态（旋转和移动）
vector<int> add(int tile_id) {
    vector<int> ret;
    string s[SIZE];
    // 读入每一行
    for (int i = 0; i < SIZE; i++) {
        cin >> s[i];
    }
    for (int rotate_num = 0; rotate_num < ROTATE_NUM; rotate_num++) {
        // x 最多向左偏移3单位，向右偏移3单位
        for (int dx = -3; dx <= 3; dx++) {
            // y 最多向左偏移3单位，向右偏移3单位
            for (int dy = -3; dy <= 3; dy++) {
                int v = get(s, dx, dy);
                if (v >= 0) {
                    ret.push_back(v);
                }
            }
        }
        rotate(s);
    }
    return ret;
}

int main() {
    vector<int> mask[3];
    for (int tile_id = 0; tile_id < TILE_NUM; tile_id++) {
        mask[tile_id] = add(tile_id);
    }
    for (int x : mask[0]) {
        for (int y : mask[1]) {
            for (int z : mask[2]) {
                if ((x | y | z) + 1 != (1 << SIZE * SIZE))
                    continue;
                if (x & y)
                    continue;
                if (x & z)
                    continue;
                if (z & y)
                    continue;
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
}