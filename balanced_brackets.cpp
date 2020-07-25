// https://www.hackerrank.com/challenges/balanced-brackets/problem

#include <cstring>
#include <cstdio>
#include <bits/stdc++.h> 

using namespace std;

int main(){

    int n,len,res;
    char word[1005];
    int table[150];
    
    table['{'] = '}';
    table['}'] = '{';
    table['['] = ']';
    table[']'] = '[';
    table['('] = ')';
    table[')'] = '(';
    
    scanf("%d\n",&n);
    for (int i=0;i<n;i++)
    {
        
        stack<char> op;
                
        res=1;
        
        scanf("%s\n",word);
        len = strlen(word);
        
        if (len%2 == 1)
        {
            res = 0;
        }
        else 
        {
            for (int j=0;j<len;j++)
            {
                
                if (word[j] == '{' || word[j] == '(' || word[j] == '[')
                {
                    op.push(word[j]);
                  
                } else 
                {   

                    if (op.empty() || word[j] != table[op.top()] )
                    {
                 
                        res = 0;
                        break;
                    } else
                    {
                 
                        op.pop();
                    }
                }
                
            }
        }
        
        if (res && op.empty()) printf("YES\n");
        else printf("NO\n");
    }


    return 0;
}
