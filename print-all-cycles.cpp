#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v(10);
void dfs(int u,vector<int>par,vector<int>&color,vector<int>&mark,int&cycleno,vector<int>vis){
    if(color[u]==2)return;
    
    color[u]=1;
    vis[u]=1;
    for(auto y:v[u]){
        if(vis[y]!=1){
        par[y]=u;
        cout<<y<<u<<endl;
         dfs(y,par,color,mark,cycleno,vis);
        }
        else if(color[y]==1&&y!=par[u]){
        int temp=y;
        
        mark[y]=cycleno;
        temp=u;
        while(y!=temp){
            
            mark[u]=cycleno;
           
            temp=par[temp];
            
        }
    cycleno++;
    }
    }
    
    color[u]=2;
}

void addEdge(int x,int y){
    v[x].push_back(y);
    v[y].push_back(x);
}
int main(){
        addEdge(0,1);
        addEdge(1,2);
        addEdge(2,0);
        addEdge(1,3);
        addEdge(3,4);
        addEdge(4,5);
        addEdge(5,6);
        addEdge(6,4);
         addEdge(2,3);
        
        int n=1;
        
         vector<int> par(10,-1),color(10,-1),mark(10,-1),vis(10,0);
        dfs(0,par,color,mark,n,vis);
        for(auto i :mark){
            
            cout<<i<<" ";
        }
    
    return 0;
}
