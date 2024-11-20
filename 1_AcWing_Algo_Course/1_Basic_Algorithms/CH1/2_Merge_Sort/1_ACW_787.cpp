// Problem: https://www.acwing.com/problem/content/789/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int q[N], tmp[N];
int n;

void merge_sort(int q[], int l, int r) {
    if (l >= r)
        return;

    // 取中点，把区间[l,r]分为两半
    int mid = (l + r) >> 1;
    // 先把左右两部分都归并排序一下
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    // i为左半边起点，j为右半边起点，把小的值分别存进tmp数组中
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    // 剩下来的值存进数组中。下面两个while只会执行一个
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    // 最后把排好序的值从tmp中拿回到q中
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
    cout << endl;
}