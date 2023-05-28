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
    cin >> n;

    vector<int> S(n+1 , 0);
    for( int i = 1 ; i <= n ; i++ ){
        cin >> S[i];
    }
    sort(S.begin()+1 , S.end());
    int len = S.size();

    int mid = (n+1)/2;
    bool flag = true;
    for( int i = 1 ; i < mid ; i ++ ){
        if( S[i] >= S[mid+i] || S[i+1] >= S[mid+i]){
            flag = false;
            break;
        }
    }

    if( flag) cout << "Yes" << endl;
    else cout << "No" << endl;

}