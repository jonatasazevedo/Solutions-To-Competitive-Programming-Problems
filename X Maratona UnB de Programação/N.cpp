#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
typedef long long ll;
using namespace std;


int main(){_
    ll n, m; cin>>n>>m;

    if(m==1 || m==3) cout<<-1<<endl;
    else if(m%5==0) cout<<m/5<<endl;
    else{
        ll ans=0;
        if(m&1){
            ans=2;
            m-=7;
        }
        ans+=(m/10)*2 + (m%10)/2;
        cout<<ans<<endl;
    }


    return 0;
}