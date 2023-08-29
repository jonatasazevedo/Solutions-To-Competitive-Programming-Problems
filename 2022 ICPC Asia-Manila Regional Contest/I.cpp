#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

#define MAX_N 20
#define MAX_M 200005
#define MAX_RAW 15
#define INF_RAW (ll(1e8+10))

int n, m;

struct Item{
  vector<int> items;
  ll raws[MAX_RAW];
} a[MAX_M];

ll rawStorage[MAX_RAW], aux[MAX_RAW];
int rawSz=0;

void sumArr(ll *a, ll *b, int n){
  for(int i=0;i<n;i++) a[i]=min(a[i]+b[i], INF_RAW);
}

bool checkPossible(int mask){
  fill(aux, aux+MAX_RAW, 0);
  // cout<<mask<<endl;

  for(int i=1;mask>0;i++, mask>>=1){
    if(!(mask&1)) continue;
    sumArr(aux, a[i].raws, rawSz);
  }

  for(int i=0;i<rawSz;i++)
    if(rawStorage[i]<aux[i])
      return false;

  return true;
}

int main(){_
  cin>>n>>m;

  for(int i=1, c, p;i<=m;i++){
    cin>>c;
    if(c==0){
      cin>>rawStorage[rawSz];
      a[i].raws[rawSz++]=1;
    }
    else{
      a[i].items.resize(c);
      for(int j=0;j<c;j++)
        cin>>a[i].items[j];
    }
  }

  for(int i=m;i>=1;i--)
    for(int itemId:a[i].items)
      sumArr(a[i].raws, a[itemId].raws, rawSz);

  int ans=0;
  for(int mask=1;mask<(1<<n);mask++){
    if(__builtin_popcount(ans)>=__builtin_popcount(mask)) continue;
    if(checkPossible(mask)) ans=mask;
  }

  // cout<<endl<<"winning mask: "<<ans<<endl;
  cout<<__builtin_popcount(ans)<<endl;

  return 0;
}