#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define sec second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
    
const int MAX_N = 200005;

ll n;
ll totalSum=0;

ll wealthies[MAX_N];

set<ll> indexes;
set<pll> wIndex;

inline bool isHegemony(){
  ll wealthiest = wIndex.rbegin()->fi;
  return 2*wealthiest > totalSum;
}

inline void updateAdd(ll i, ll wAdd){
  wIndex.erase({wealthies[i], i});
  wIndex.emplace(wealthies[i]+=wAdd, i);
  totalSum+=wAdd;
}

inline void colapse(ll i, ll w){
  auto itErase = indexes.find(i);
  ll wAdd = w/2, iL=-1, iR=-1;

  if(itErase!=indexes.begin()) iL=*prev(itErase);
  if(next(itErase)!=indexes.end()) iR=*next(itErase);

  if(iL>=0) updateAdd(iL, wAdd);
  if(iR>=0) updateAdd(iR, wAdd);

  totalSum-=w;
  indexes.erase(i);
  wIndex.erase({w, i});

  printf("%lld %lld\n", i, w);

}

int main(){
  scanf("%lld", &n);
  // cin>>n;

  for(ll i=1;i<=n;i++){
    scanf("%lld", &wealthies[i]);
    // cin>>wealthies[i];
    indexes.emplace(i);
    wIndex.emplace(wealthies[i], i);
    totalSum+=wealthies[i];
  }

  while(!wIndex.empty()){
    ll i, w;
    if(!isHegemony()){
      w = wIndex.rbegin()->fi;
      i = wIndex.lower_bound({w, LLONG_MIN})->sec;
    }
    else tie(w,i) = *(wIndex.begin());

    colapse(i, w);
  }

  return 0;
}