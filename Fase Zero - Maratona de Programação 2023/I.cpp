#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int QT_BT = 10;
const int INVALID_ANS = (1<<QT_BT);

vector<int> flips[QT_BT];

bool check(int panel, int press){
  for(int i=0;i<QT_BT;i++)
    if(press&(1<<i))
      for(int x:flips[i])
        panel ^= (1<<(x-1));
  
  return panel==((1<<QT_BT)-1);
}

//a < b (binary)
bool cmpBin(int a, int b){
  if(a==b) return false;

  for(;a!=0 && b!=0;a>>=1, b>>=1){
    if(a&1 && b&1) continue;
    if(a&1) return true;
    if(b&1) return false;
  }

  return a==0;
}

int main(){_
  flips[0]={2, 5};
  flips[1]={1, 5, 6, 3};
  flips[2]={2, 6, 7, 4};
  flips[3]={3, 7};
  flips[4]={1, 2, 6, 8};
  flips[5]={5, 2, 3, 8, 9, 7};
  flips[6]={9, 6, 3, 4};
  flips[7]={5, 6, 9, 10};
  flips[8]={10, 8, 6, 7};
  flips[9]={8, 9};

  int panel=0;
  for(int i=0, x;i<QT_BT;i++){
    cin>>x;
    panel+=(x<<i);
  }

  int ans=INVALID_ANS;
  for(int i=0;i<(1<<QT_BT);i++){
    if(ans!=(1<<QT_BT) &&  __builtin_popcount(i) > __builtin_popcount(ans) ) continue;
    if(check(panel, i) && (__builtin_popcount(i) < __builtin_popcount(ans) || cmpBin(i, ans))) ans=i;
  }


  if(ans==INVALID_ANS){
    cout<<(-1)<<endl;
    return 0;
  }

  int qt = __builtin_popcount(ans);
  cout<<qt<<endl;

  bool space=false;
  for(int i=1;ans!=0;i++, ans>>=1){
    if(!(ans&1)) continue;
    
    if(space) cout<<" ";
    else space=true;
    
    cout<<i;
  }
  if(qt>0) cout<<endl;
  

  return 0;
}
