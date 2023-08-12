#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main(){_
  string a;
  cin>>a;

  int cntX=0;
  for(char c:a)
    if(c=='X') cntX++;

  if(cntX!=2) cout<<"?\n";
  else{
    if(a[1]=='X') cout<<"Alice\n";
    else cout<<"*\n";
  }

  return 0;
}