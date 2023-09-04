#include<bits/stdc++.h>

using namespace std;

int n,k,x;

int main(){
    cin >> n >> k;
    int cnt =0;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x <= k) cnt++;
    }

    cout << cnt << "\n";
}