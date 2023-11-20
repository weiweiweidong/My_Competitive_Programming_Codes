// 这道题其实是我自己没仔细看懂题意，所以浪费了很多时间。实际上并没有那么难

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long LL;

int main(){
    int n;
    cin >> n;
    int k = n;
    string s = "";
    while( n-- ){
        char c;
        cin >> c;
        s += c;
    }
    
    int a = 0 , t = 0;
    for( auto c : s ){
        if( c == 'T' ) t++;
        else if( c == 'A' ) a++;
    }

    if( t > a ) cout << "T" << endl;
    else if( t < a ) cout << "A" << endl;
    else if( t == a ){
        a = 0 , t = 0;
        for( auto c : s ){
            if( c == 'T' ){
                t++;
                if( t == k/2 ){
                    cout << "T" << endl;
                    break;
                }
            }
            else if( c == 'A' ){
                a++;
                if( a == k/2 ){
                    cout << "A" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}