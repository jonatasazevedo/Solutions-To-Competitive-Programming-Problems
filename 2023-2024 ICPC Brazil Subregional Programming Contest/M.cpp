#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

const int MAX_N = 105;

int g[MAX_N][MAX_N], g2[MAX_N][MAX_N], n;

set<pair<int,int>> ans;

int main(){_
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>g[i][j];
            g2[i][j] = g[i][j];
        }

    bool coerente=true;
    for(int k=0;coerente && k<n;k++)
        for(int i=0;coerente && i<n;i++)
            for(int j=i+1;coerente && j<n;j++){
                if(k==i || k==j) continue;
                int escala = g[i][k]+g[k][j];
                if(escala<g[i][j]) coerente=false;
                else if(escala==g[i][j]){
                    ans.emplace(i,j);
                    // cout<<"("<<i<<","<<j<<","<<k<<") ";
                }
            }

    if(!coerente) cout<<-1<<endl;
    else{
        cout<<ans.size()<<endl;
        // for(auto x:ans) cout<<"("<<x.first<<","<<x.second<<") ";
        // cout<<endl;
    }

    return 0;
}