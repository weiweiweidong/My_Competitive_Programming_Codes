#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long H, W;
    int N;
    cin >> H >> W >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // 统计每种大小的巧克力块需求总面积
    vector<long long> area(26, 0);  // 由于0 <= A_i <= 25
    for (int i = 0; i < N; ++i) {
        area[A[i]] += (1LL << A[i]) * (1LL << A[i]);
    }
    if (area[A[N - 1]] > H * W)
        cout << " No" << endl;

    // 检查是否可以满足具体的尺寸需求
    long long totalArea = H * W, currentArea = 0;
    for (int i = 25; i >= 0; --i) {
        currentArea <<= 2;  // 当前尺寸的巧克力块面积翻倍处理更大尺寸
        currentArea += area[i];
        if (currentArea > totalArea) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
