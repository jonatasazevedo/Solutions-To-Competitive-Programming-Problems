#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;

int main(){_
    int n;
    cin>>n;
    string s1,s2; 
    cin>>s1>>s2;
    bool flag = true;
    for(int i=0;i<n && flag;i++){
        if(s1[i]=='1' && s2[i]=='1') flag=false;
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}