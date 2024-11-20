// Problem: https://www.acwing.com/problem/content/790/
// 使用归并排序求数列中的逆序对的数量

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int q[N], tmp[N];
int n;

LL merge_sort(int q[], int l, int r) {
    if (l >= r)
        return 0;

    int mid = (l + r) >> 1;
    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        // 说明没有逆序对，直接排序即可
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        // 有逆序对，并且q[i]后面的数都有逆序对
        else {
            res += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
    return res;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    cout << merge_sort(q, 0, n - 1) << endl;
}