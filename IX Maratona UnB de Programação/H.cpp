#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define MAX_N 500005

int parent[MAX_N],rnk[MAX_N],life[MAX_N]; 

void begin_sets(int n){
  for(int i=0;i<=n;i++){
    parent[i] = i;
    rnk[i] = 1;
    life[i] = 3;
  }
}

int find_set(int v){
  if(parent[v]==v) return v;
  return parent[v] = find_set(parent[v]);
}

void union_set(int v,int w){
  int vSet = find_set(v), wSet = find_set(w);
  if(vSet==wSet) return;

  parent[wSet] = vSet;
  rnk[vSet]+=rnk[wSet];
}

int main(){_
  int n,a,j,op,x,y,resp=0;
  cin>>n>>a>>j;
  begin_sets(n);
  for(int i=0;i<a;i++){
    cin>>op>>x>>y;
    int x1 = find_set(x);
    int x2 = find_set(y);
    if(x1!=x2 && life[x1]>0 && life[x2]>0){
      if(op==1){
        //cout<<x1<<" encostou "<<x2<<endl;
        if(life[x1]==life[x2]){
          life[x1] = max(0,life[x1]-1);
          life[x2] = max(0,life[x2]-1);
        }
        else{
          if(life[x1]<life[x2]) swap(x1,x2);
          union_set(x1,x2);
          life[x1]+=life[x2];
        }
        //cout<<life[x1]<<" vidas "<<life[x2]<<endl;
      }
      else{
          if(life[x1]!=life[x2]){
            if(life[x1]<life[x2]) swap(x1,x2);
            life[x2]=0;
            if(find_set(j)==x1) resp++;
          }
      }
    }
  }
  cout<<resp<<endl;

  return 0;
}



