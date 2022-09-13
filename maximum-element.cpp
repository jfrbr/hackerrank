// Link:https://www.hackerrank.com/challenges/maximum-element/problem

#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int,int> ii;

int main(){


    int n,op,num,res=-1;
    scanf("%d\n",&n);

    
    stack<ii> s;

    while (n--){
        scanf("%d\n",&op);
        if (op == 1){
            scanf("%d\n",&num);

            if (s.empty()) res = -1;
            else res = s.top().second;

            res = res > num ? res : num;

            ii pair = make_pair(num, res);
            s.push(pair);

        } else if (op == 2){
            s.pop();
        } else {
            printf("%d\n", s.top().second);
        }
    }

    return 0;
}
