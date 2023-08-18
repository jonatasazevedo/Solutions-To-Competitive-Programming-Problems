#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
#define MAX_N 100005

ll x[MAX_N],y[MAX_N],z[MAX_N],w[MAX_N];
ll n;
ll wsoma,xwsoma,ywsoma,zwsoma;

ll arredonda(ll a,ll b){
    return (a+b-1)/b;
}

ll funcao(ll a,ll b,ll vet[]){
    ll val1 = a/b,val2 = arredonda(a,b);
    if(val1==val2) return val1;
    ll calc1=0,calc2=0;
    for(int i=0;i<n;i++){
        calc1+=((vet[i]-val1)*(vet[i]-val1)*w[i]);
        calc2+=((vet[i]-val2)*(vet[i]-val2)*w[i]);
    }
    if(calc1<=calc2) return val1;
    else return val2;
}

int main(){_
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>z[i]>>w[i];
        wsoma+=w[i];
        xwsoma+=(x[i]*w[i]);
        ywsoma+=(y[i]*w[i]);
        zwsoma+=(z[i]*w[i]);
    }
    cout<<funcao(xwsoma,wsoma,x)<<" "<<funcao(ywsoma,wsoma,y)<<" "<<funcao(zwsoma,wsoma,z)<<endl;   
}