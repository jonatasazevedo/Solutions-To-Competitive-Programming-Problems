#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
using namespace std;

const int MAX_N = 100005;
int a[MAX_N], dp[MAX_N];

int solve(int i){
  if(dp[i]!=-1) return dp[i];
  dp[i]=0; //unknown
  return dp[i] = solve(a[i]) + 1;
}

int main(){_
  int n; cin>>n;
  for(int i=1;i<=n;i++) cin>>a[i];
  
  fill(dp, dp+n+2, -1);
  int ans=0;
  for(int i=1;i<=n;i++)
    ans = max(ans, solve(i));
  
  cout<<ans<<endl;
  
  return 0;
}