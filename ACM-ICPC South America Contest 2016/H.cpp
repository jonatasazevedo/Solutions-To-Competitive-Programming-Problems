#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;

int main(){_
    ll x,n,k;
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    cin>>n>>k;
    ll soma = 0;
    for(int i=1;i<=n;i++){
        cin>>x;
        soma+=x;
        if(i%(k+1)==0){
          pq.push(x);
          //cout<<x<<" ins"<<endl;
        }
        else if(!pq.empty()){
            ll y = pq.top();
            if(y<x){
                //cout<<y<<" tirado e insere "<<x<<endl;
                pq.pop();
                pq.push(x);
            }
        }
    }
    while(!pq.empty()){
        ll y = pq.top(); pq.pop();
        //cout<<y<<endl;
        soma-=y;
    }
    cout<<soma<<endl;
    
}