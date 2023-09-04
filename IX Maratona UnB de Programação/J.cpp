#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
using namespace std;
typedef long long ll;
const int MAX_N = 100010;

vector<int> g[MAX_N];
ll color[MAX_N],peso[MAX_N];
ll pd[MAX_N][2];

int n;

ll dfs(int x, int p, int flag){
  if(pd[x][flag] != -1) return pd[x][flag];

  if(g[x].size() ==  1 and x != 1) return pd[x][flag] = flag*peso[x];
  else if(flag == 1){
    pd[x][flag] = peso[x];
    for(int v: g[x]){
      if(v != p){
        pd[x][flag] += dfs(v,x,0);
      }
    }
  }else{
    pd[x][flag] = 0;
    for(int v: g[x]){
      if(v != p){
        pd[x][flag] += max(dfs(v,x,1),dfs(v,x,0));
      }
    }
  }
  
  return pd[x][flag]; 
}

set<int> resp;

void print(int x, int p, int flag){
  if(flag == 1){
    resp.insert(x);
    for(int v: g[x]){
      if(v != p){
        print(v,x,0);
      }
    }
  }else{
    for(int v: g[x]){
      if(v != p){
        if(pd[v][1] > pd[v][0]){
          print(v,x,1);
        }else{
          print(v,x,0);
        }
        //pd[x][flag] += max(dfs(v,x,1),dfs(v,x,0));
      }
    }
  }
}

int main(){_
  cin >> n;

  for(int i=1;i<=n;i++){
    cin >> peso[i];
  }

  memset(pd,-1,sizeof(pd));

  int u,v;
  for(int i=0;i<n-1;i++){
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  ll ans = max(dfs(1,0,1), dfs(1,0,0));

  cout << ans << "\n";

  if(pd[1][0] > pd[1][1]){
    print(1,0,0);
  }else{
    print(1,0,1);
  }


  for(int it: resp){
    cout << it << " ";
  }
  cout << "\n";

}