#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define fi first
#define sec second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;

#define MAX_N 100005

pi a[MAX_N];

ll area(pi c, pi p1, pi p2){
  p1.fi -= c.fi; p1.sec -= c.sec;
  p2.fi -= c.fi; p2.sec -= c.sec;
  return (p1.first*p2.sec) - (p1.sec*p2.fi);
}

int main() {_
  int n; cin>>n;
  
  for(int i=0;i<n;i++) cin>>a[i].fi>>a[i].sec;
  pi c;
  cin>>c.fi>>c.sec;

  bool ok=true;
  ll x=0, xAbs=0;
  for(int i=0;i<n;i++){
    double aux = area(c, a[i], a[(i+1)%n]);
    if(aux==0){ok=false; break;}
    x+=aux;
    xAbs+=abs(aux);
    // cout<<aux<<endl;
  }

  cout<<(ok && abs(x)==xAbs ? "S" : "N")<<endl;

  return 0;
}