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

using pl = pair<LL, LL>;

int main() {
    long long n, k;  // n是点的数量，k是最大操作数
    cin >> n >> k;
    vector<long long> x(n), y(n);      // 存储所有点的x坐标和y坐标
    map<long long, long long> mx, my;  // 用来记录 坐标值 和 出现的次数
    for (long long i = 0; i < n; i++) {
        cin >> x[i] >> y[i];  // 读入x和y坐标值
        mx[x[i]]++;           // 记录x坐标出现次数
        my[y[i]]++;           // 记录y坐标出现次数
    }
    vector<pl> xv, yv;
    for (auto& nx : mx) {
        xv.push_back(nx);  // 将 x坐标值和出现次数 作为一个pair，插入xv数组中
    }
    for (auto& nx : my) {
        yv.push_back(nx);  // 将 y坐标值和出现次数 作为一个pair，插入yv数组中
    }
    long long xl = 0, xr = xv.size() - 1;  // 记录x最左端和最右端的index
    long long yl = 0, yr = yv.size() - 1;  // 记录y最左端和最右端的index
    while (k > 0) {
        long long gx = xv[xr].first - xv[xl].first;  // 记录x的跨度
        long long gy = yv[yr].first - yv[yl].first;  // 记录y的跨度
        long long fx, fy;
        long long hx, hy;
        long long cx, cy;
        if (gx != 0) {
            if (xv[xl].second < xv[xr].second) {
                hx = xv[xl + 1].first - xv[xl].first;
                cx = xv[xl].second;
                fx = -1;
            } else {
                hx = xv[xr].first - xv[xr - 1].first;
                cx = xv[xr].second;
                fx = 1;
            }
        }
        if (gy != 0) {
            if (yv[yl].second < yv[yr].second) {
                hy = yv[yl + 1].first - yv[yl].first;
                cy = yv[yl].second;
                fy = -1;
            } else {
                hy = yv[yr].first - yv[yr - 1].first;
                cy = yv[yr].second;
                fy = 1;
            }
        }
        if (gx == 0 && gy == 0) {
            break;
        } else if (gx < gy) {
            // shorten y
            long long opt = min({k / cy, hy, gy - gx});
            if (opt == 0) {
                break;
            }
            k -= cy * opt;
            if (fy == -1) {
                yv[yl].first += opt;
            } else {
                yv[yr].first -= opt;
            }
        } else if (gx > gy) {
            // shorten x
            long long opt = min({k / cx, hx, gx - gy});
            if (opt == 0) {
                break;
            }
            k -= cx * opt;
            if (fx == -1) {
                xv[xl].first += opt;
            } else {
                xv[xr].first -= opt;
            }
        } else {
            // once x==y, let's keep it
            // shorten x&y
            long long opt = min({k / (cx + cy), hx, hy});
            if (opt == 0) {
                break;
            }
            k -= (cx + cy) * opt;
            if (fy == -1) {
                yv[yl].first += opt;
            } else {
                yv[yr].first -= opt;
            }

            if (fx == -1) {
                xv[xl].first += opt;
            } else {
                xv[xr].first -= opt;
            }
        }
        if (xl != xr) {
            if (xv[xl].first == xv[xl + 1].first) {
                xv[xl + 1].second += xv[xl].second;
                xl++;
            } else if (xv[xr].first == xv[xr - 1].first) {
                xv[xr - 1].second += xv[xr].second;
                xr--;
            }
        }
        if (yl != yr) {
            if (yv[yl].first == yv[yl + 1].first) {
                yv[yl + 1].second += yv[yl].second;
                yl++;
            } else if (yv[yr].first == yv[yr - 1].first) {
                yv[yr - 1].second += yv[yr].second;
                yr--;
            }
        }
    }
    {
        long long gx = xv[xr].first - xv[xl].first;
        long long gy = yv[yr].first - yv[yl].first;
        cout << max(gx, gy) << "\n";
    }
    return 0;
}