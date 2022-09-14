// Problem: https://www.hackerrank.com/challenges/sparse-arrays/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main(){
    
    
    int n,q,res;
    scanf("%d\n",&n);
    map<string, int> strings;
    string s;
    
    while (n--){
        cin >> s;
        strings[s]++;
    }
    
    scanf("%d\n",&q);
    
    while (q--){
        cin >> s;
        if (strings[s] > 0){
            res = strings[s];
        } else {
            res = 0;
        }
        
        printf("%d\n",res);
    }
    
    return 0;
}
