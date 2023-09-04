#include<bits/stdc++.h>

using namespace std;

int n,a[100010], b[100010];

int main(){
     cin >> n;

     for(int i=0;i<n;i++){
        cin >> a[i];
     }

     for(int i=0;i<n;i++){
        cin >> b[i];
     }

     sort(a,a+n);
     sort(b,b+n);

     
     int ans = 0;
     for(int i=0;i<n;i++){
        ans = max(ans,abs(b[i]-a[i]));
     }

     cout << ans << "\n";
}