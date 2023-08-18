#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;

#define MAX_K 100005

const ll MOD = 1'000'000'007;
ll mod(ll a, ll m){
    return ((a%m)+m)%m;
}

ll modPow(ll b, ll p, ll m){
    if(p == 0) return 1;
    ll ans = modPow(b, p/2,m);
    ans = mod(ans*ans,m);
    if(p&1) ans = mod(ans*b, m);
    return ans;
}

ll invM(ll m,ll n){
    return modPow(m,n-2,n);
}

ll fat[MAX_K],invfat[MAX_K];

struct elemento{
  ll a,b;
  void md(ll m){
    a = mod(a,m);
    b = mod(b,m);
  }
  elemento operator*(elemento const &obj){
    elemento res;
    res.a = ((a*obj.a)%MOD + (5*b*obj.b)%MOD)%MOD;
    res.b = ((a*obj.b)%MOD + (b*obj.a)%MOD)%MOD;
    return res;
  }
  elemento operator+(elemento const &obj){
    elemento res;
    res.a = a + obj.a;
    res.b = b + obj.b;
    res.md(MOD);
    return res;
  }
  elemento operator-(elemento const &obj){
    elemento res;
    res.a = a - obj.a;
    res.b = b - obj.b;
    res.md(MOD);
    return res;
  }

  elemento inv(){
    elemento res;
    ll t1 = mod((a*a)%MOD-(5*b*b)%MOD,MOD);
    ll t2 = mod((5*b*b)%MOD-(a*a)%MOD,MOD);
    t1 = invM(t1,MOD);
    t2 = invM(t2,MOD);
    res.a = mod(a*t1,MOD);
    res.b = mod(b*t2,MOD);
    return res;
  }
}a,b,ck,neutro;



elemento expfast(elemento base,ll p,ll m){
  if(p == 0) return neutro;
  elemento ans = expfast(base,p/2,m);
  ans=ans*ans;
  if(p&1) ans=ans*base;
  return ans;
}

void preprocess(ll k){
  fat[0]=fat[1]=invfat[1]=invfat[0]=1;
  for(ll i=2;i<=max(k,2LL);i++){
    fat[i] = (i*fat[i-1])%MOD;
    invfat[i] = (invM(i,MOD)*invfat[i-1])%MOD;
  }
  a = {invfat[2],invfat[2]}; //(1/2,1/2)
  b = {invfat[2],invM(-2+MOD,MOD)}; // (1/2 , -1/2)
  neutro = {1,0}; 
  ck = {0,invM(5,MOD)}; //(0,1/5) = c
  ck = expfast(ck,k,MOD); //c^k
}

ll comb(ll a,ll b){
  return (((invfat[b]*invfat[a-b])%MOD) * fat[a])%MOD;
}

int main(){_
  ll n,k;
  cin>>n>>k;
  preprocess(k);
  elemento ans = {0,0};
  for(ll j=0;j<=k;j++){
    elemento combi = {comb(k,j),0};
    elemento x1 = expfast(a,k-j,MOD);
    elemento x2 = expfast(b,j,MOD);
    elemento x = x1*x2;
    elemento p;
    if(x.a==1 && x.b==0){ // RAZAO DA PG = 1
      p.a = (x.a*n)%MOD;
      p.b = (x.b*n)%MOD;
    }
    else{
      elemento num = expfast(x,n+1,MOD)-x;
      elemento den = x-neutro;
      p = num*den.inv();
    }
    elemento res = combi*p;
    if(j%2==0) ans = ans+res;
    else ans = ans-res;

  }
  ans = ck * ans;
  cout<<ans.a<<endl;
}