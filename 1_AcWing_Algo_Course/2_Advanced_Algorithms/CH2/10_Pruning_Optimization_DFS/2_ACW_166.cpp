// Problem: https://www.acwing.com/problem/content/168/

// 这道题目思维难度很大，还是要多练习几遍的
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 定义常量：N为数独大小(9x9)，M为2的N次方
// M的二进制形式为：1后面9个0（实数为512），所以并不大
// 备注：int是4个字节，32位长度，取值范围为 +-2e9 这个规模
const int N = 9, M = 1 << N;

// ones数组记录每个状态中1的个数
// map数组用于将2的幂次映射到对应的数字(0-8)
int ones[M], maps[M];

// row[i]表示第i行可以填入的数字的状态
// col[i]表示第i列可以填入的数字的状态
// cell[i][j]表示第(i,j)个3x3宫格可以填入的数字的状态
int row[N], col[N], cell[3][3];

// 存储数独盘面的字符数组
char str[100];

// 初始化函数：将所有行、列、格子的状态都设为全集(所有数字都可以填)
// 全集：111111111（9个1）
void init() {
    for (int i = 0; i < N; i++)
        // (1 << N) - 1 表示N个1，即111111111
        row[i] = col[i] = (1 << N) - 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cell[i][j] = (1 << N) - 1;
}

// 在位置(x,y)填入或删除数字t
// is_set为true表示填入，false表示删除
void draw(int x, int y, int t, bool is_set) {
    if (is_set)
        str[x * N + y] = '1' + t;  // 填入数字
    else
        str[x * N + y] = '.';  // 删除数字，填入点

    int v = 1 << t;  // 将t转换为位表示
    if (!is_set)
        v = -v;  // 如果是删除操作，取负数

    // 更新对应的行、列、宫格的状态
    row[x] -= v;
    col[y] -= v;
    cell[x / 3][y / 3] -= v;
}

// 返回x的最低位的1
// 例如：x = 1010，返回 10
int lowbit(int x) {
    return x & -x;
}

// 获取位置(x,y)可以填入的数字的状态
// 通过与运算(&)确保满足行、列、宫格的限制
int get(int x, int y) {
    return row[x] & col[y] & cell[x / 3][y / 3];
}

// 深度优先搜索函数
// cnt表示还需要填入的数字个数
bool dfs(int cnt) {
    if (!cnt)
        return true;  // 如果没有需要填入的数字了，说明解决完成

    // 找到可选择数字最少的位置(x,y)
    int minv = 10;
    int x, y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (str[i * N + j] == '.')  // 如果是空位
            {
                int state = get(i, j);   // 获取可填入的数字状态
                if (ones[state] < minv)  // 如果可填入的数字更少
                {
                    minv = ones[state];
                    x = i, y = j;
                }
            }

    // 尝试在位置(x,y)填入所有可能的数字
    int state = get(x, y);
    for (int i = state; i; i -= lowbit(i)) {
        int t = maps[lowbit(i)];  // 获取当前尝试的数字
        draw(x, y, t, true);      // 填入数字
        if (dfs(cnt - 1))
            return true;       // 继续搜索
        draw(x, y, t, false);  // 恢复现场
    }
    return false;
}

void solve() {  // 初始化map数组：将2的幂次映射到对应的数字
    for (int i = 0; i < N; i++)
        maps[1 << i] = i;

    // 初始化ones数组：计算[0,512)每个状态中1的个数
    for (int i = 0; i < 1 << N; i++)
        for (int j = 0; j < N; j++)
            ones[i] += i >> j & 1;

    // 读入数独盘面，直到输入'e'结束
    while (cin >> str, str[0] != 'e') {
        init();       // 初始化状态
        int cnt = 0;  // 记录需要填入的数字个数

        // 处理输入的数独盘面
        for (int i = 0, k = 0; i < N; i++)
            for (int j = 0; j < N; j++, k++)
                if (str[k] != '.')  // 如果不是空位，说明已经填入了数字
                {
                    int t = str[k] - '1';  // 将字符转换为数字(0-8)
                    draw(i, j, t, true);   // 更新状态
                } else
                    cnt++;  // 统计空位数量

        dfs(cnt);             // 解决数独
        cout << str << endl;  // 输出结果
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}