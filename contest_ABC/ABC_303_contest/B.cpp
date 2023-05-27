#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <math.h>
#include <string.h>

typedef long L;
typedef long long LL;
using namespace std;

const int N = 60;
int g[N][N];

int main(){
    // n 为总人数，m为拍照次数
    int n , m;
    cin >> n >> m;
    // 用 A 存储下来每次拍照的结果(高为m+1，宽为n+1)
    vector<vector<int>> A( m+1 , vector<int>(n+1 , 0));

    // 将关系都存进 vector 里面
    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            cin >> A[i][j];
        }
    }

    for( int i = 1 ; i <= m ; i++ ){
        for( int j = 1 ; j < n ; j++ ){
            int a = A[i][j],  b = A[i][j+1];
            g[a][b] = 1 , g[b][a] = 1;
        }
    }

    for( int i =1 ; i <= n ; i++ ){
        g[i][i] = 1;
    }
    
    int res = 0;
    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 1 ; j <= n ; j++ ){
            if( !g[i][j] ) res++;
        }
    }

    cout << res/2 << endl;

    
}