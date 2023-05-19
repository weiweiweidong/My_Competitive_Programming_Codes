#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long long LL;
vector<int> res;

void m( int a , int b ){
    if( abs(a-b) == 1 ){
        res.push_back(a);
    }
    else{
        if( a > b ){
            for( int i = a ; i > b ; i--) res.push_back(i);
        }
        else{
            for( int i = a ; i < b ; i++) res.push_back(i);
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n , 0);
    for( int i = 0 ; i < n ; i++ ){
        int x;
        cin >> x;
        nums[i] = x;
    }

    for( int i = 0 ; i < n ; i++ ){
        if( i == n-1 ) res.push_back(nums[i]);
        else{
            m( nums[i] , nums[i+1]);
        }
    }

    for( int i = 0 ; i < res.size() ; i++ ){
        cout << res[i];
        if( i < res.size()-1 ) cout << " ";
    }
    cout << endl;
    return 0;
}