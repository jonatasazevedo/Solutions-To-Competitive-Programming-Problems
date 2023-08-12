#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); \
cin.tie(NULL); cout.tie(NULL);
#define fi first
#define sec second
#define eb emplace_back
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

#define pb push_back
ll _sieve_size;
bitset<10000010> bs;
vll p;
ll gcd(ll a,ll b){ return b ? gcd(b, a%b):a;}

ll mod(ll a, ll m){
    return ((a%m)+m)%m;
}
void sieve(ll upperbound){
  _sieve_size = upperbound +1;
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2;i< _sieve_size;i++){
    if(bs[i]){
      for(ll j=i*i; j< _sieve_size; j+= i) bs[j] = 0;
      p.pb(i);
    }
  }
}

ll exgcd(ll a, ll b, ll& x, ll& y) {
  if(!b) {
    x = 1; y = 0; return a;
  }
  ll r = exgcd(b,a%b,y,x);
  y -= a/b*x;
  return r;
}

int main(){_
    sieve(10000005);
    ll n=2,m,x,y;
    cin>>m;
    for(auto j: p){
        if(gcd(m,j)==1){
            n=j;
            break;
        } 
    }
    exgcd(n,m,x,y);
    cout<<mod(x,m)<<endl;
}