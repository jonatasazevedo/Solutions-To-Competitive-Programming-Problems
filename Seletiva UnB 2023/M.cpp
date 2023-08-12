#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false); \
cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long ll;
#define MOD 998244353
#define MAX_N 2000005
ll tam[MAX_N],fat[MAX_N],invfat[MAX_N];
ll n;
ll calcular(int j){
    if(j>=n) return 1; //fora da árvore
    
    ll subEsquerda = calcular(2*j);
    ll subDireita = calcular(2*j+1);
    ll qtSubEsquerda = tam[2*j];
    ll qtSubDireita = tam[2*j+1];
    ll qtSubArvores = qtSubDireita + qtSubEsquerda;
    
    ll comb = ((invfat[qtSubEsquerda] * invfat[qtSubDireita])%MOD * fat[qtSubArvores])%MOD;
    
    return ((subEsquerda*subDireita)%MOD * comb)%MOD;
}

ll mod(ll a, ll m){
    return ((a%m)+m)%m;
}
ll modPow(ll b, ll p, ll m){
    if(p == 0) return 1;
    ll ans = modPow(b, p/2,m);
    ans = mod(ans*ans,m);
    if(p&1) ans = mod(ans*b, m);
    return ans;
}

ll invM(ll m,ll n){
    return modPow(m,n-2,n);
}
int main(){_
    
    cin>>n;
    
    tam[2*n+1]=tam[2*n]=0;
    
    for(int i=n;i>0;i--){
        tam[i] = 1 + tam[2*i] + tam[2*i+1];
    }
    invfat[0]=fat[0]=1;
    
    for(int i=1;i<=n;i++){
        fat[i]=(i*fat[i-1])%MOD;
        invfat[i]=(invM(i,MOD)*invfat[i-1])%MOD;
    }
    
    ll res = calcular(1);
    cout<<res<<endl;
    
    return 0;
}