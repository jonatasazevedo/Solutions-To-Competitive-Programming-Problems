#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
#define eb emplace_back
using namespace std;
typedef long long ll;

const int MAX_N = 200005;

int n, m;

stack<int, vector<int>> esteira;
vector<int> aux;
int ans=0;

void updateEsteira(int curTime){
  while(!esteira.empty() && esteira.top()<=curTime){
    if(esteira.top()==curTime) ans++;
    esteira.pop();
  }
}

void insertBread(int x, int curTime){
  if(esteira.empty() || esteira.top()>=x){
    esteira.emplace(x);
    return;
  }

  for(int i=0;i<m && !esteira.empty();i++){
    int top = esteira.top();
    if(top>curTime) aux.eb(top);
    else if(top==curTime) ans++;
    esteira.pop();
  }
  aux.eb(x);
  sort(aux.begin(), aux.end());

  while(!aux.empty()){
    esteira.emplace(aux.back());
    aux.pop_back();
  }
}

int main(){_
  cin>>n>>m;

  for(int curTime=0, x;curTime<n;curTime++){
    cin>>x;
    x+=curTime;
    updateEsteira(curTime);
    insertBread(x, curTime);
  }

  int curTime;
  while(!esteira.empty()){
    curTime=esteira.top();
    updateEsteira(curTime);
  }

  cout<<ans<<endl;

  return 0;
}