#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define fi first
#define sec second
#define eb emplace_back
using namespace std;
typedef long long ll; 
typedef pair<int32_t, int32_t> pi32;
typedef tuple<int32_t,int32_t,int32_t> ti32;

#define MAX_N 3005

ll gcd(ll a, ll b){
  return b ? gcd(b, a%b) : a;
}

map<ti32,vector<int>> lines;;

pi32 pts[MAX_N];

int main() {_
  int n; cin>>n;

  for(int i=0;i<n;i++)
    cin>>pts[i].fi>>pts[i].sec;
  
  vector<int> ans;
  for(int i=0;i<n;i++){
    auto [x1,y1] = pts[i];
    lines.clear();
    for(int j=i+1;j<n;j++){
      auto [x2,y2] = pts[j];

      int32_t A = y1-y2, B = x2-x1, C = x1*y2-x2*y1;
      ll div = gcd(gcd(A,B),C);

      if(A<0 || (A==0 && B<0)) div*=-1;

      ti32 line(A/=div, B/=div, C/=div);
      
      auto &it = lines[line];

      if(it.empty()) it.eb(i); 
      it.eb(j);
    }

    for(auto it:lines)
      if(it.sec.size()>ans.size())
        ans = it.sec;
  }

  cout<<ans.size()<<endl;
  for(size_t i=0;i<ans.size();i++)
    cout<<pts[ans[i]].fi<<" "<<pts[ans[i]].sec<<endl;

  return 0;
}