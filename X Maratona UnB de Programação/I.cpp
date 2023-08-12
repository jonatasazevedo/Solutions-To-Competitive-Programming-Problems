#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
typedef long long ll;
using namespace std;
#define MAX_N 200005

int v[MAX_N];
map<int,bool> mapa;
int main(){_
    int n,s;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mapa[v[i]]=true;
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        int res = v[i]- s;
        if(mapa.find(res)!=mapa.end()){
            flag = true;
            break;
        }
        res = v[i] + s;
        if(mapa.find(res)!=mapa.end()){
            flag = true;
            break;
        }
    }
    if(flag) cout<<"Sim"<<endl;
    else cout<<"Nao"<<endl;

    return 0;
}