#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define fi first
#define sec second

ll n,l,c,m[510][510];

string str;

ll ml[8] = {0,-1,-1,-1,0,1,1,1}, mc[8] = {-1,-1,0,1,1,1,0,-1};

ll how_many_ney(ll a, ll b){
    ll cnt = 0;
    for(ll i=0;i<8;i++){
        ll nl = a + ml[i];
        ll nc = b + mc[i];
        if((nl >= 0 and nl < l) and (nc >= 0 and nc < c)) cnt++;
    }

    return cnt;
}

void distribute(ll x, ll a, ll b){
    

    for(ll i=0;i<8;i++){
        ll nl = a + ml[i];
        ll nc = b + mc[i];
        if((nl >= 0 and nl < l) and (nc >= 0 and nc < c)){
            m[nl][nc] += x;
            m[a][b] -= x;
        }
    }
}


pair<ll,ll> move(ll a, ll b){
    ll mx = -1;
    ll na,nb;
    for(ll i=0;i<8;i++){
        ll nl = a + ml[i];
        ll nc = b + mc[i];
        if((nl >= 0 and nl < l) and (nc >= 0 and nc < c)){
            if(m[nl][nc] > mx){
                na = nl, nb =nc;
                mx = m[nl][nc];
            }
        }
    }

    return {na,nb};
}


int main(){_

    cin >> l >> c;


    for(ll i=0;i<l;i++){
        for(ll j=0;j<c;j++){
            cin >> m[i][j];
        }
    }
    if(l==1 && c==1){
        cout<<m[0][0]<<endl;
        return 0;
    }

    ll a,b;
    cin >> a >> b;
    
    a--;
    b--;

    /*cout << a << " " << b << "\n";
    for(ll i=0;i<l;i++){
    for(ll j=0;j<c;j++){
            cout <<  m[i][j] << " ";
        }
        cout << "\n";
    }*/

    ll n_times = l+c;
    for(ll k=0;k<n_times;k++){

        ll ney = how_many_ney(a,b);
        ll send = m[a][b]/ney;

        distribute(send,a,b);
        pair<ll,ll> top = move(a,b);
        a = top.first;
        b = top.second;

       /* cout << a << " " << b << "\n";
       for(ll i=0;i<l;i++){
        for(ll j=0;j<c;j++){
                cout <<  m[i][j] << " ";
            }
            cout << "\n";
        }*/
    }

    ll mx = 0;
    for(ll i=0;i<l;i++){
        for(ll j=0;j<c;j++){
            mx = max(mx,m[i][j]);
        }
    }   


    cout << mx << "\n";

    return 0;
}