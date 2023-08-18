#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int main(){_
    ll n, f;

    cin>>n>>f;

    ll x,y;
    while(n--){
        cin>>x>>y;
        if(x<y) swap(x,y);

        if(f>=x) f+=x;
        else if(f>=y) f+=y;
        else{
            cout<<"N\n";
            return 0;
        }
    }

    cout<<"S\n";

    return 0;
}