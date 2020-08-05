// https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem

#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <stack>

using namespace std;

typedef pair<int,int> ii;

int matriz[11][11];
int vis[11][11];

int dx[] = {0,-1,0,1,1,-1,1,-1};
int dy[] = {1,0,-1,0,-1,1,1,-1};

int n,m;

int checkBounds (int nx, int ny){
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) return 0;
    else return 1;
}

int dfs (int u, int w){

   int res=0, nx, ny;
   vis[u][w] = 1;
   
   stack<ii> s;
   
   s.push( make_pair(u,w));
   
   while (!s.empty()){
       
       ii curr = s.top();
       s.pop();
       
       res++;
       
       for (int i=0; i < 8; i++){
            nx = curr.first + dx[i];
            ny = curr.second + dy[i];
            
            if (checkBounds(nx,ny) && matriz[nx][ny] && !vis[nx][ny]){
               vis[nx][ny] = 1;
               s.push( make_pair(nx,ny));
            }
       }
   }
   
   return res;
  
}

int main(){

    scanf("%d\n%d\n",&n,&m);
    
    memset(matriz,0,sizeof(matriz));
    memset(vis,0,sizeof(vis));
    
    for (int i=0; i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&matriz[i][j]);
        }
        scanf("\n");
    }
    
    int res = 0;
    
    for (int i=0;i<n;i++){
        for (int j=0; j < m;j++){
            if (matriz[i][j] && !vis[i][j]){
                res = max(res,dfs(i,j));
            }        
        }
    }
    
    printf("%d\n",res);   
    
    return 0;
}
