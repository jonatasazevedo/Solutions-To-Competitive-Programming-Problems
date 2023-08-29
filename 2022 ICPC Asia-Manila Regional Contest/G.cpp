#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define sec second
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pii> ranges;
vector<pii> events;

int main(){_
  int n,k,a,b;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    
    if(b-a+1>=k) ranges.eb(0,k-1);
    else{
      int l = a%k, r=b%k;

      if(l<=r) ranges.eb(l, r);
      else{
        ranges.eb(0,r);
        ranges.eb(l, k-1);
      }
    }
    // else if(a==b) ranges.eb(a%k,b%k); 5,1
  }
  //sort(ranges.begin(),ranges.end());

  // for(int i=0;i<ranges.size();i++){
  //   cout<<ranges[i].fi<<" "<<ranges[i].sec<<endl;
  // }

  for(auto p:ranges){
    events.eb(p.fi, 0); //0-> start
    events.eb(p.sec, 1); //1-> end
  }
  sort(events.begin(), events.end());

  ll val=0, maxVal=0;
  for(auto p:events){
    if(p.sec==0) maxVal=max(maxVal, ++val);
    else val--;
  }

  cout<<maxVal<<endl;

  return 0;
}