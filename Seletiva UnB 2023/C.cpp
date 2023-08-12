#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); \
cin.tie(NULL); cout.tie(NULL);
#define fi first
#define sec second
#define eb emplace_back
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

const int MAXN = 1010;

char atendido[MAXN];
ll p[MAXN],r[MAXN],t[MAXN];
int n;

ll check(int i, ll tempo){
    if(atendido[i]) return -1;

    ll ini =0, fim = 3000000000000000;
    ll k = -1;
    while(ini <= fim){
        ll mid = (ini+fim)/2;

        if(mid*p[i] + mid*r[i] <= tempo){
            k = mid;
            ini = mid+1;
        }else{
            fim = mid -1;
        }
    }

    if(tempo <= ((k+1)*p[i])+k*r[i]) return k*p[i] + k*r[i];
    else return -1;
}

ll next(ll tempo){

    ll tempo_aux = 1000000000000000;
    for(int i=0;i<n;i++){
        if(atendido[i]) continue;

        ll ini =0, fim = 1000000000000000;
        ll k = -1;
        while(ini <= fim){
            ll mid = (ini+fim)/2;

            if(mid*p[i] + mid*r[i] > tempo){
                k = mid;
                fim = mid-1;
            }else{
                ini = mid +1;
            }
        }

        tempo_aux = min(k*p[i] + k*r[i],tempo_aux);
    }

    return tempo_aux;
}

int main(){_
    
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> t[i] >> p[i] >> r[i];
    }

    ll tempo = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

// cout << t[0] << "\n";

    int x = n;
    while(x--){

        //verificar quem está na fila
        for(int i=0;i<n;i++){
            ll top = check(i,tempo);
            if(top != -1){
                pq.push({top,i});
            }
        }

        //cout << pq.size() << "\n";
        
        // se tiver vazia eu vejo quem é o proximo 
        // a chegar e avanço o tempo pra ele
        if(pq.empty()){
            //cout << "vsf\n";

            tempo = next(tempo);

            //cout << tempo << "\n";
            for(int i=0;i<n;i++){
                ll top = check(i,tempo);
                if(top != -1){
                    pq.push({top,i});
                }
            }
        }

        //marcar cliente como já atendido   
        pll at = pq.top();

        //cout << at << "\n";
        //cout << t[0] << "\n";



        pq.pop();

        //cout << "tempo 1 " <<  tempo << " " << at << " " << t[at] <<  "\n";

        tempo = tempo + t[at.second];
        atendido[at.second] = 1;

        //cout << "tempo 2 " << tempo + t[at] <<" " << t[at] << "\n";

        //cout << "Tempo " <<  tempo << "\n";
        while(!pq.empty()) pq.pop();
    }

    cout << tempo << "\n";
}