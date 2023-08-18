#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;

#define MAX_N 1005

int a[MAX_N][MAX_N], ans=0, n, k;

int main(){_
    cin>>n>>k;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];

    for(int i=0;i+k<=n;i++){
        for(int j=0;j+k<=n;j++){
            int i1=i, i2=i+k-1, j1=j, j2=j+k-1;
            if(a[i1][j1]==a[i1][j2] &&
               a[i1][j1]==a[i2][j1] &&
               a[i1][j1]==a[i2][j2]) ans++;
        }
    }
            
    cout<<ans<<endl;

    return 0;
}