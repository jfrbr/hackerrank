// https://www.hackerrank.com/challenges/new-year-chaos/problem

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define pb push_back

int main(){

    int t,n,people, aux;
    
    scanf("%d\n",&t);
    
    while (t--){
    
        scanf("%d\n",&n);
        vector<int> line;
        
        for (int i=0;i < n; i++){
            scanf("%d ",&people);
            line.pb(people);
        }
        int res = 0;
        
        for (int i = n-1; i >= 0; i--){
            
            if ((line[i] - (i+1)) > 2){
                res = -9999;
                break;
            }
            
            for (int j= max(0,line[i]-2); j < i; j++){
                if (line[j] > line[i]) res++;
            }
        
        }
        if (res < 0) printf("Too chaotic\n");
        else printf("%d\n",res);
    
    }


    return 0;
}
