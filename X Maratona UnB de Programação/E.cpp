#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define eb emplace_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int t;
ll p,i,l;

int main(){_

    cin >>  t;
    
    while(t--){
        cin >> p >> i >> l;

        if(i==0){
            cout<<0<<endl;
            continue;
        }

        ll inspecoes = (1LL << (i-1));

        ll ini = 1, fim = l/ inspecoes;
        ll resp = -1;

        //cout << ini << " " << fim << "\n";
        while(ini <= fim){
            ll mid = (ini+fim)/2;

            //cout << mid << " " << inspecoes*mid << "\n";

            if(inspecoes*mid <= l){
                ini = mid + 1;
                resp = mid;
            }else{
                fim = mid - 1;
            }
        }


        //cout << resp << "\n";
        if(resp == -1){
            cout << "Melhor chamar o Selso.\n";
        }else  cout << max(0LL,p - resp) << "\n";

    }



    return 0;
}