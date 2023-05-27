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

pair<int,int> nextposition(int x , int y , char d ){
    if( d == 'R' ) x++;
    else if( d == 'L' ) x--;
    else if( d == 'U' ) y++;
    else if( d == 'D' ) y--;
    return {x, y};
}

int main(){
    // 预处理
    int n , m , h , k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;

    set<pair<int,int>> items;
    for( int i = 1 ; i <= m ; i++ ){
        int a, b;
        cin >> a >> b;
        items.insert({a, b});
    }

    // 开始移动
    int res = 0;
    int x = 0 , y = 0;
    for( int i = 0 ; i < s.size() ; i++ ){
        pair<int,int> next = nextposition( x , y , s[i]);    // 获取下一步位置
        h--;    // 体力-1

        // 如果体力不够，说明走不到这个位置
        if( h < 0 ) break;
        // 如果下一个点有食物
        if( h >= 0 && h < k ){
            if( items.find(next) != items.end() ){
                h = k;
                items.erase(next);
            }
        }
        
        res++;  // 能运行到这里，说明能走到这里，移动步数+1
        if( res == n ) break;
        x = next.first , y = next.second;
    }

    if( res == n ) cout << "Yes" << endl;
    else cout << "No" << endl;
    
}