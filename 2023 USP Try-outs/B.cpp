#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

ll a,b,n,x;

int main(){_
    cin >> n;

    vector<ll> impa;
    for(int i=0;i<n;i++){
        cin >> x;

        if(x&1){
            impa.push_back(i);
        }
    }   

    if(impa.size()&1){
        cout << -1 << "\n";
        return 0;
    }

    if(impa.size() == 0){
        cout << 0 << "\n";
        return 0 ;
    }
    
    int top = impa.size();
    impa.push_back(impa[0]);



    cin >> a >> b;

    ll sm1 = 0; 
    for(int i=0;i<top;i+=2){
        ll jesse =  min(abs(impa[i]-impa[i+1]),
                (n - max(impa[i],impa[i+1])) + min(impa[i],impa[i+1]) )*min(a,b);
        sm1 += jesse; 
    }

    ll sm2 = 0; 
    for(int i=1;i<=top;i+=2){
        ll jesse = min(abs(impa[i]-impa[i+1]),
                (n- max(impa[i],impa[i+1])) + min(impa[i],impa[i+1]) )*min(a,b);
        sm2 += jesse; 
    }

    cout << min(sm1,sm2) << "\n";
}