#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

#define MAX_N 200005
#define LOG 20

int up[MAX_N][LOG];
vector<pll> gAux[MAX_N], g[MAX_N];
int depth[MAX_N];
ll depthW[MAX_N];

bool visited[MAX_N];
void dfsOrder(int u){
    visited[u]=true;

    for(auto aux: gAux[u]){
        ll w, v;
        tie(w, v) = aux;

        if(visited[v]) continue;
        // cout<<u<<" -> "<<v<<" ("<<w<<")\n";
        g[u].eb(w,v);
        dfsOrder(v);
    }
}

void dfs(int u){
    for(auto aux: g[u]){
        ll w, v;
        tie(w, v) = aux;
        if(depth[v] != 0) continue;


        depth[v] = depth[u] + 1;
        depthW[v] = depthW[u] + w;
        up[v][0] = u; // u is parent of v

        for(int j=1;j<LOG;j++){
            up[v][j] = up[up[v][j-1]][j-1];
        }
        dfs(v);
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]){
        swap(a,b);
    }

    ll k = depth[a] - depth[b];

    for(int j=LOG-1;j>=0;j--){
        if(k & (1 << j)){
            a = up[a][j];
        }
    }

    if(a==b) return a;

    for(int j=LOG-1;j>= 0;j--){
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

ll deal(int a, int b){
    int abLCA = lca(a,b);
    // cout<<"LCA de "<<a<<" e "<<b<<": "<<abLCA<<endl;
    // cout<<depthW[a]<<" "<<depthW[b]<<" "<<depthW[abLCA]<<endl;
    return (depthW[a]-depthW[abLCA]) + (depthW[b]-depthW[abLCA]);
}

int main(){_
    ll n, q; cin>>n;

    for(ll i=1, u, v, w;i<n;i++){
        cin>>u>>v>>w; 
        gAux[u].eb(w,v);
        gAux[v].eb(w,u);
    }
    dfsOrder(1);
    dfs(1);

    cin>>q;

    ll a, b, c;
    while(q--){
        cin>>a>>b>>c;
        cout<<deal(a,b)+deal(b,c)<<endl;
    }

    return 0;
}