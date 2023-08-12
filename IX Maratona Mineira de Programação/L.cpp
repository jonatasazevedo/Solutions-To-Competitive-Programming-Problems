#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
#define fi first
#define sec second

#define MAX_CN 2005

char a[MAX_CN], ans[MAX_CN];
int n;

int main(){_
    cin>>a>>n;
    int len = strlen(a);
    if(n==1 || n==len){
        cout<<a<<endl;
        return 0;
    }

    int k = 2*(n-1);

    for(int l=0, j=0;l<n;l++){ //line by line
        for(int i=l, curK=k-2*l ; i<len ; i+=curK, curK=k-curK){
            ans[i]=a[j++];
            if(curK==0) curK=k;
        }
    }
    ans[len]='\0';

    cout<<ans<<endl;

    return 0;
}