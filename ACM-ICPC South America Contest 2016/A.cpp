#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define vi vector<int>
#define ii pair<int,int>
#define pii pair<int,ii>
#define oo 1000000123
using namespace std;

int main(){_
    int vetor[4],soma;
    for(int i=0;i<4;i++) cin>>vetor[i];
    sort(vetor,vetor+4);
    soma=abs(vetor[3]+vetor[0]-vetor[1]-vetor[2]);
    cout<<soma<<endl;
}
