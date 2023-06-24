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


int main(){
    int n;
    string s;
    cin >> n >> s;

    string ans;
    int cnt = 0;
    for( char c : s ){
        if( c == '(' ){
            ans += c , cnt++;
        }
        else if( c == ')' ){
            if( cnt > 0 ){
                while( ans.size() && ans.back() != '(' ) ans.pop_back();
                ans.pop_back();
                cnt--;
            }
            else ans += c;
        }
        else ans += c;
    }
    cout << ans << endl;
}