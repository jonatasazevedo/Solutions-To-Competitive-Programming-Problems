#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
typedef long long ll;
using namespace std;
#define MAX_N 200005

int v[MAX_N];
map<int,bool> mapa;
int main(){_
    string dica,s,aux;
    cin>>dica;
    cin.ignore(1000,'\n');
    while(1){
        getline(cin,s);
        if(s=="Que horas sao? Sao 5 e 60!") break;
        aux="";
        for(int i=0;i<s.size();i++){
            if(i==0 || (s[i-1]==' '))  aux+=tolower(s[i]);
        }
        int pontDica=0;
        for(int i=0;i<aux.size();i++){
            if(pontDica==dica.size()) break;
            if(dica[pontDica]==aux[i]) pontDica++; 
        }
        if(pontDica==dica.size()) cout<<"#lorota"<<endl;
        else cout<<"#tereteteu"<<endl;
    }

    return 0;
}