// https://www.hackerrank.com/challenges/ctci-making-anagrams/problem

#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_map>
#include <cmath>
#include <iostream>

using namespace std;


int main(){

    string a,b;
    int res = 0;
    
    cin >> a;
    cin >> b;
    
    int map_a[26];
    int map_b[26];
    
    memset(map_a, 0, sizeof(map_a));
    memset(map_b, 0, sizeof(map_b));
    
    
    for (int i=0; i < a.size(); i++){
        map_a[a[i]-'a'] = map_a[a[i]-'a'] + 1;
    }
    
    for (int i=0; i < b.size(); i++){
        map_b[b[i]-'a'] = map_b[b[i]-'a'] + 1;
    }
    
    for (int i=0; i < 26; i++){
        res += abs(map_a[i] - map_b[i]);
    }
    
    printf("%d\n",res);
    
    return 0;
}
