#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;

typedef long long ll;


int main(){_
    cout<<fixed<<setprecision(4);
    double x,y;
    cin>>x>>y;
    bool flag = false;
    double resp=LLONG_MAX;
    if(y>x){
        resp = min(resp,2*y-x);
        flag = true;
    }
    if(2*y>x){
        resp = min((x+2*y)/2,resp);
        flag = true;
    }
    if(2*x>y && y>x){
        resp = min(2*x,resp);
        flag = true;
    }
    if(flag) cout<<resp<<endl;
    else cout<<-1<<endl;   
    
    return 0;
}