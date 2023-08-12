#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main(){_
  ll x; cin>>x;

  cout<<x<<endl;
  while(x>=10){

    x = 3*(x/10) + x%10;

    cout<<x<<endl;
  }

  return 0;
}
