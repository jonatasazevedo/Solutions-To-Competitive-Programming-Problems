#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MAX_NT = 1005;

//index       timeUsed
ll dp[MAX_NT][MAX_NT], path[MAX_NT][MAX_NT];
ll n, t;
struct Course{
  ll t, d;
} a[MAX_NT];

ll solve(ll i, ll timeRemain){
  if(timeRemain<0) return INT_MIN;
  if(i>=n) return 0;
  if(dp[i][timeRemain]!=-1) return dp[i][timeRemain];

  path[i][timeRemain] = timeRemain;
  dp[i][timeRemain] = solve(i+1, timeRemain);

  ll aux = solve(i+1, timeRemain-a[i].t) + a[i].d;

  if(aux>dp[i][timeRemain]){
    path[i][timeRemain] = timeRemain-a[i].t;
    dp[i][timeRemain] = aux;
  }

  return dp[i][timeRemain];
}

vector<ll> ans;

void constructPath(ll i, ll timeRemain){
  if(i>=n) return;

  ll v = path[i][timeRemain];

  if(v!=timeRemain) ans.eb(i+1);

  constructPath(i+1, v);
}

int main(){_
  cin>>n>>t;
  
  for(int i=0;i<n;i++) cin>>a[i].t>>a[i].d;

  for(int i=0;i<=n;i++)
    fill(dp[i], dp[i]+t+1, -1);

  solve(0,t);
  constructPath(0, t);

  cout<<ans.size()<<endl;
  if(!ans.empty()){
    for(ll x:ans) cout<<x<<" ";
    cout<<endl;
  }

  return 0;
}