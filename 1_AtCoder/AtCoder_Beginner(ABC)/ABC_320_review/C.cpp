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

int main() {
    int M;
    cin >> M;
    string S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    S1 = " " + S1;
    S2 = " " + S2;
    S3 = " " + S3;

    int res = 1e9;
    // 先后三次拍停
    for (int i = 0; i <= M; i++) {
        for (int j = i + 1; j <= i + 1 + M; j++) {
            for (int k = j + 1; k <= j + 1 + M; k++) {
                // 表示分别在 i j k 秒时拍 S1 S2
                // S3。因为不规定拍钮顺序，所以全都抽出来
                char a1 = S1[i % M + 1], a2 = S1[j % M + 1], a3 = S1[k % M + 1];
                char b1 = S2[i % M + 1], b2 = S2[j % M + 1], b3 = S2[k % M + 1];
                char c1 = S3[i % M + 1], c2 = S3[j % M + 1], c3 = S3[k % M + 1];

                if (a1 == b2 && b2 == c3)
                    res = min(res, k);
                if (a1 == b3 && b3 == c2)
                    res = min(res, k);

                if (b1 == a2 && a2 == c3)
                    res = min(res, k);
                if (b1 == c2 && c2 == a3)
                    res = min(res, k);

                if (c1 == a2 && a2 == b3)
                    res = min(res, k);
                if (c1 == b2 && b2 == a3)
                    res = min(res, k);
            }
        }
    }
    if (res == 1e9)
        cout << -1 << endl;
    else
        cout << res << endl;
}