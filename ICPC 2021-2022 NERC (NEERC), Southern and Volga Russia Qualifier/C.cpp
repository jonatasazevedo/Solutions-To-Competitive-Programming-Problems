#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;

typedef long long ll;

const int MAX_N=1005, QT_DAYS=5;
int n;
int a[MAX_N][QT_DAYS];

bool checkPossible(int d1, int d2){
    int d1Possible=0, d2Possible=0, bothPossible=0;
    for(int i=0;i<n;i++){
        if(a[i][d1] && a[i][d2]) bothPossible++;
        else if(a[i][d1]) d1Possible++;
        else if(a[i][d2]) d2Possible++;
        else return false;
    }
    return abs(d1Possible-d2Possible)<=bothPossible; 
}

int main(){_
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<QT_DAYS;j++)
            cin>>a[i][j];

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<QT_DAYS;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    bool ok=false;
    for(int d1=0;!ok && d1<QT_DAYS;d1++){
        for(int d2=d1+1;!ok && d2<QT_DAYS;d2++){
            ok = checkPossible(d1, d2);
            // if(ok){
            //     cout<<d1<<" "<<d2<<endl;
            // }
        }
    }

    cout<<(ok ? "YES" : "NO")<<endl;

    return 0;
}