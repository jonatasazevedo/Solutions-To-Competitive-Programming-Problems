#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
 
int n,m,k,r[4],ty;
vector<vi> g_o;

int solve(){
  int res = 1000000000;
  if(n>1){
    for(int mid = n - (k+1);mid <= k;mid++){
      int aux = 0;
      if(g_o[mid][0] == ty) aux += 2;
      aux += (n*m) - r[ty];
      res = min(res,aux);
    }
  }else{
    for(int mid = m - (k+1);mid <= k;mid++){
      //cout << mid << "\n";
      int aux = 0;
      if(g_o[0][mid] == ty) aux += 2;
      aux += (n*m) - r[ty];
      res = min(res,aux);
    }
  }

  return res;
}

int main(){ _
  cin >> n  >> m >> k;
 
  g_o.assign(n , vi(m, 0));

  int v = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> g_o[i][j];
      r[g_o[i][j]]++;
    }
  }

  int ans = 1000000000;

  if(n==1 || m == 1){
    
    for(ty=1;ty<=3;ty++){
      if(m*n <= k || m*n > 2*k+1) break;
      ans = min(ans,solve());
    } 
  }else{
    for(ty=1;ty<=3;ty++){
      if(m*n != k+1) break;
      ans = min(ans,(n*m) - r[ty]);
    }
  }
  
  if(ans == 1000000000) cout << "-1\n";
  else{
    cout << ans << "\n";
  }
 
}
 
 