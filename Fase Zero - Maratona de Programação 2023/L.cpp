#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main(){_

  int n, m, s;
  cin>>n>>m>>s;

  int x, y, r;
  ll sum=0;
  while(s--){
    cin>>x>>y>>r;

    int up=max(1, x-r), down=min(n, x+r), left=max(1, y-r), right=min(m, y+r); 
    sum+=(down-up+1)*(right-left+1);
  }
  
  cout<<sum/(n*m)<<endl;

  return 0;
}