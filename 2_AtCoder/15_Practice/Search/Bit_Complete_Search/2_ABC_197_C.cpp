// Problem: https://atcoder.jp/contests/abc197/tasks/abc197_c

/*
    备注：XOR：相同为 0，不同为 1

    思路：
    一个长度为N的数组A的分段状态，可以写成一个 N-1 位的二进制数字st。
        例如：假设N为6，那么st的长度为5，00000~11111，表示“无任何分隔”和“每个元素后都分隔”。
    二进制数字的第i位为 1，表示在原数组index为i的元素后面进行了分隔。
    N最大为20，那么st最大为2^19=524288，并不是很大的数字。可以暴力枚举所有的分隔状态。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 25;
int A[N];
int n;

void solve() {
    // 读入数组
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    // 给一个很大的数
    // 本题中 A[i]上限为 2^30=1.07e9，res 取值一定要比这个数大
    int res = 2e9;

    // st 表示插入状态
    for (int st = 0; st < (1 << (n - 1)); st++) {
        int xor_ed = 0;  // 存储 xor 运算的结果
        int or_ed = 0;   // 存储 or 运算的结果

        // 向右移动j位
        for (int j = 0; j <= n; j++) {
            // 在范围内，就做一次or运算
            if (j < n)
                or_ed |= A[j];

            // j==n 的时候说明遍历到头了：最后做一次 xor 运算收尾
            // st >> j & 1 表示判断第j位是否为1，是1的就做xor运算，并重置or
            if (j == n || (st >> j & 1)) {
                xor_ed ^= or_ed;
                or_ed = 0;
            }
        }
        // 更新当前分段方式的结果
        res = min(res, xor_ed);
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}