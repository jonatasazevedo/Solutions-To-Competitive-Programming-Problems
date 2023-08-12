#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
 
typedef long long ll;
typedef vector<ll> vll;
#define pb push_back
ll _sieve_size;
bitset<10000010> bs;
vll p;

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

ll qtDiv(ll N){
  ll ans=1;
  for(int i=0; (i< p.size()) && (p[i]*p[i] <= N);i++){
    ll power=0;
    while(N%p[i] == 0){
      N /= p[i];
      power++;
    }
    ans*=(power+1);
  }
  return (N != 1) ? 2*ans : ans;
}

int main(){_
    ll a,b,c,lim,res=1;
    cin>>a;
    b=a+1;
    c=2*a+1;
    lim=sqrt(2*a+1);
    sieve(lim);
    if(a%2==0) a/=2;
    else b/=2;
    if(a%3==0) a/=3;
    else if(b%3==0) b/=3;
    else c/=3;
    res*=qtDiv(a);
    res*=qtDiv(b);
    res*=qtDiv(c);
    cout<<res<<endl;
    return 0;
}