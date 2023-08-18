#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define eb emplace_back
#define fi first
#define sec second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

const int MAX_N = 2505;
const int MAX_Q = 5005;

typedef enum{
  DEAD=-2,      //not existent
  UNCOLORED=-1, //existent, not processed (colored)
  WHITE=0,      //inserted white (corn)
  BLACK=1       //inserted black (bean)
} Color;

int n, m, q;

vector<int> g[MAX_N];
Color colors[MAX_N];
vector<int> blackVs;

pi ops[MAX_Q];

void insertV(int v){
  if(colors[v]!=UNCOLORED) return;

  int qtWhite=0, qtBlack=0;
  for(int w:g[v]){
    if(colors[w]==WHITE) qtWhite++;
    else if(colors[w]==BLACK) qtBlack++;
  }

  colors[v] = qtBlack>=qtWhite ? WHITE : BLACK;
  if(colors[v]==BLACK) blackVs.eb(v);
}

int main(){_
  cin>>n>>m>>q;

  for(int i=0, u, v;i<m;i++){
    cin>>u>>v;
    g[u].eb(v);
    g[v].eb(u);
  }

  fill(colors, colors+n+2, UNCOLORED);
  for(int i=0;i<q;i++){
    cin>>ops[i].fi;
    if(ops[i].fi==2) continue;
    cin>>ops[i].sec;
    colors[ops[i].sec]=DEAD;
  }

  for(int i=1;i<=n;i++) insertV(i);

  stack<string> ans;
  for(int i=q-1;i>=0;i--){
    if(ops[i].fi==1){
      colors[ops[i].sec]=UNCOLORED;
      insertV(ops[i].sec);
    }
    else{
      string aux;
      aux+=to_string(blackVs.size());
      for(int v:blackVs) aux+=" "+to_string(v);
      ans.emplace(aux);
    }
  }

  while(!ans.empty()){
    cout<<ans.top()<<endl;
    ans.pop();
  }

  return 0;
}