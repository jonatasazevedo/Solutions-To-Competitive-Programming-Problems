#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main(){_
  ll a, b, c;
  char k;
  cin>>a>>b>>c>>k;

  ll ans;
  if(k=='A')
    ans = a + (3*b + 5*c)/2;
  else if(k=='B')
    ans = (2*a + 5*c)/3 + b;
  else
    ans = (2*a + 3*b)/5 + c;
  
  cout<<ans<<endl;

  return 0;
}