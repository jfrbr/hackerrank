// https://www.hackerrank.com/challenges/find-the-running-median/problem

#include <cstdio>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

int main(){


    int n;
    float number;
    float med = 0;
    
    scanf("%d\n",&n);
    
    priority_queue<float> max_heap;
    priority_queue<float, vector<float>, greater<float> > min_heap;
    
    scanf("%f\n",&number);
    med = number;

    max_heap.push(number);
    
    printf("%.1f\n",number);
    
    for (int i=1;i<n;i++){
        scanf("%f\n",&number);
        
        if ( max_heap.size() > min_heap.size() ){
        
            if (number < med){
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(number);
            } else {
                min_heap.push(number);
            }
            med = (min_heap.top() + max_heap.top()) /2;
        
        } else if ( max_heap.size() == min_heap.size() ){
            if (number < med){
                max_heap.push(number);
                med = max_heap.top();
            
            } else {
                min_heap.push(number);
                med = min_heap.top();
            }
        
        } else {
            if (number > med){
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(number);
            } else {
                max_heap.push(number);
            }
            
            med = (min_heap.top() + max_heap.top()) /2;
        }
        
        printf("%.1f\n",med);
    }


    return 0;
}
