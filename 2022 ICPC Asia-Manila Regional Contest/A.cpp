#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main(){_
  ll a=-2, b=1, c=-14, d=17, x;
  cin>>x;

  ll ans;
  if(x<=(-3)) ans=-((x+4)*(x+4))+8;
  else if(x<=2) ans=a*x+b;
  else ans=x*x*x+c*x+d;

  cout<<ans<<endl;

  return 0;
}