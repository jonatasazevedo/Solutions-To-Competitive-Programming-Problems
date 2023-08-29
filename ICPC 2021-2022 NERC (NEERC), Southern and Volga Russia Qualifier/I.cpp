#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;

typedef long long ll;

const int MAX_N=200010;

int n,u,v;
int sub = -1;
int subTree[MAX_N], pai[MAX_N],color[MAX_N];
vector<int> g[MAX_N];


void dfs(int x, int p){
    subTree[x] = 1;

    for(int v: g[x]){
        if(v != p){
            pai[v] = x;
            dfs(v, x);

            subTree[x] += subTree[v];
        }
    }

    if(subTree[x] == n/2){
        sub = x;
    }
}

void dfs2(int x, int p){
    color[x] = 1;

    for(int v: g[x]){
        if(v != p){
            dfs2(v, x);  
        }
    }
}

int main(){_
    cin>>n;
    
    for(int i=0;i<n-1;i++){
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,0);

    if(sub == -1){
        cout << "NO\n";
    }else{
        cout << "YES\n";

        dfs2(sub,pai[sub]);

        for(int i=1;i<=n;i++){
            cout << color[i] << " ";
        }
        cout << "\n";
    }

    
    
    return 0;
}