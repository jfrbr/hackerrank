#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

int main(){

    
    int n,m,a,b,k;
    
    ll res = 0;
    
    scanf("%d %d\n",&n,&m);
    
    vector<ll> arr(n,0);

    while (m--){

        scanf("%d %d %d\n",&a,&b,&k);
        arr[a-1] += (ll)k;
        arr[b] -= (ll)k;
    }
    ll sum=0;
    for (int i=0; i<n;i++){
        sum += arr[i];
        res = max(res,sum);
    }
    
    printf("%lld\n",res);

    return 0;
}
