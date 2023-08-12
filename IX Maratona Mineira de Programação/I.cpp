#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

#define MAX_N 2000005

ll a[MAX_N], b[MAX_N];

void preSumJump(ll *a, ll *b, ll n, ll start){
  b[0]=a[start];
  for(ll i=start+2, j=1;i<n;i+=2, j++)
    b[j] = a[i] + b[j-1];
}

ll maxInWindowPre(ll *arr, ll n, ll k){
  multiset<ll> w;
  for(ll i=0;i<k;i++) w.emplace(arr[i]);

  ll best=(*w.rbegin());
  for(ll i=k;i<n;i++){
    w.erase(arr[i-k]);
    w.emplace(arr[i]);
    best = max(best, (*w.rbegin()) - arr[i-k]);
  }

  return best;
}

int main() {_
  ll n;
  cin>>n;

  for(ll i=0;i<n;i++) cin>>a[i];
  copy(a, a+n, a+n);

  ll aSz=2*n, bSz=n, k=n/2, ans;
  
  preSumJump(a, b, aSz, 0);
  ans = maxInWindowPre(b, bSz, k);
  
  preSumJump(a, b, aSz, 1);
  ans = max(ans, maxInWindowPre(b, bSz, k));

  cout<<ans<<endl;

  return 0;
}