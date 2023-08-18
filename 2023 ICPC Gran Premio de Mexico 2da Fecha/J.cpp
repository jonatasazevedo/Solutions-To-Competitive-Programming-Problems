#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
typedef vector<int> vi;


vi dfs_num, dfs_low, dfs_parent, articulation_vertex,vis;
int dfsNumberCount,dfsRoot, rootChildren;
vector<int> AL[100010],G[100010];
int comp;

vector<pair<int,int>> pontes;
int mark[1000010];

void articulationPointAndBridge(int u){
    dfs_num[u] = dfsNumberCount++;
    dfs_low[u] = dfs_num[u];

    for(int v : AL[u]){

        //cout << u << " " << v << "\n";

        if(dfs_num[v] == -1){
            dfs_parent[v] = u;
            if(u == dfsRoot) ++rootChildren;

            articulationPointAndBridge(v);

            if(dfs_low[v] > dfs_num[u]){
                //cout << u << " " << v << "\n";
                pontes.push_back({u,v});
            }
            else{
                mark[u] = 1;
                mark[v] = 1;
            }

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }else if(v!= dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

void dfs(int u){
    vis[u] = comp;

    for(int v: G[u]){
        if(vis[v] == 0){
            dfs(v);
        }
    }
}

int n,m,q;

int main(){ _

 cin >> n >> m >> q;    
    
    int u,v;
    for(int i=0;i<m;i++){
        cin >> u>> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    dfs_num.assign(n+1,-1);
    dfs_low.assign(n+1,0);
    dfs_parent.assign(n+1,-1);articulation_vertex.assign(n+1,0);
    dfsNumberCount = 0;

    articulationPointAndBridge(1);


    for(pair<int,int> it: pontes){
        if(mark[it.first] == 0 && mark[it.second] == 0){
            G[it.first].push_back(it.second);
            G[it.second].push_back(it.first);
        }
    }

    vis.assign(n+1,0);
    comp = 1;
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            dfs(i);
            comp++;
        }
    }

    int e,s;
    while(q--){
        cin >> e >> s;
        if(vis[e] == vis[s]) cout << "YES\n";
        else cout << "NO\n";
    }
}