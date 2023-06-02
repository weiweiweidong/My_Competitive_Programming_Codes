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

// 用于计算各位和，并判断是否在界限范围内
bool cal( int x , int a , int b ){
    int res = 0;
    while( x ){
        res += (x%10);
        x /= 10;
    }
    if( res <= b && res >= a ) return true;
    return false;
}

int main(){
    int n , a , b;
    cin >> n >> a >> b;

    int res = 0;
    for( int i = 0 ; i <= n ; i++ ){
        if( cal(i ,a , b) ) res += i;
    }
    
    cout << res << endl;
}