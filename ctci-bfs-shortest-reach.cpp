// https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include<bits/stdc++.h>
#include <vector>

# define INF 0x3f3f3f3f

using namespace std;

typedef pair<int,int> ii;

int main(){

    int q,n,m,a,b,start;
    int arr[1005][1005];
    
    scanf("%d\n",&q);
        
    for (int i=0;i<q;i++){
    
        scanf("%d %d\n",&n,&m);
        memset(arr,0,sizeof(arr));
        
        for (int j=0;j<m;j++){
            scanf("%d %d\n",&a,&b);
            arr[a][b] = 6;
            arr[b][a] = 6;
        }
        scanf("%d\n",&start);
        
        
        // dijkstra
        priority_queue< ii, vector <ii> , greater<ii> > pq;

	    int dist[1005];
	    memset(dist, INF, sizeof(dist));
	    
	    int vis[1005];
	    memset(vis,0,sizeof(vis));
	    
	    pq.push(make_pair(0, start));
	    dist[start] = 0;
	    
	    while (!pq.empty()){
		    int u = pq.top().second;
		    pq.pop();
		    vis[u] = 1;

		    for (int k = 1; k <= n; k++){
			    int weight = arr[u][k] == 0 ? INF : arr[u][k];

			    if (!vis[k] && dist[k] > dist[u] + weight)
			    {
				    dist[k] = dist[u] + weight;
				    pq.push(make_pair(dist[k], k));
			    }
		    }
	    }
        
        for (int i=1;i<=n;i++){
            if (start != i){
                if (dist[i] == INF) printf("-1 ");
                else printf("%d ", dist[i]);
            }
        }
        printf("\n");
    }


    return 0;
}
