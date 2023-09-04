#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;

typedef long long ll;

int main(){_
    ll d, c, r, x;

    cin>>d>>c>>r;

    queue<ll> cansativa, revigorante;

    for(ll i=0;i<c;i++){
        cin>>x;
        cansativa.emplace(x);
    }

    for(ll i=0;i<r;i++){
        cin>>x;
        revigorante.emplace(x);
    }  

    ll ans=0;
    while(!cansativa.empty()){
        ll xC = cansativa.front(); 
        if(xC<=d){
            d-=xC;
            cansativa.pop();
            ans++;
        }
        else if(revigorante.empty()) break;
        else{
            d += revigorante.front(); revigorante.pop();
            ans++;
        }
    }
    ans+=revigorante.size();

    cout<<ans<<endl;

    return 0;
}