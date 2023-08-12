#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define eb emplace_back
using namespace std;

typedef long long ll;
int res=-1;
map<char,int> mapa,mapa_res;
vector<char> letras;
string s1,s2,s3;

bool semZeroEsquerda(){
    if(s1.size()!=1){
        for(auto c: s1){
            if(mapa[c]!=0) break;
            else return false;
        }
    }
    if(s2.size()!=1){
        for(auto c: s2){
            if(mapa[c]!=0) break;
            else return false;
        }   
    }
    if(s3.size()!=1){
        for(auto c: s3){
            if(mapa[c]!=0) break;
            else return false;
        }
    }
    return true;
}

int transformarStringEmInteiro(string &s){
    int num=mapa[s[0]];
    for(int i=1;i<s.size();i++){
        num*=10;
        num+=mapa[s[i]];
    }
    return num;
}
void calcular(){
    
    if(semZeroEsquerda()){
        int num1 = transformarStringEmInteiro(s1);
        int num2 = transformarStringEmInteiro(s2);
        int num3 = transformarStringEmInteiro(s3);
        if(num1+num2==num3){
            if(res<num3){
                res = num3;
                mapa_res = mapa;
            }
        }
    }
}

void solve(int i){
    if(i==letras.size()){
       calcular();
       return;
    } 
    for(int j=0;j<10;j++){
        mapa[letras[i]]=j;
        solve(i+1);
    }
}

int main(){
    
    cin>>s1>>s2>>s3;
    for(auto c: s1) mapa[c]=-1;
    for(auto c: s2) mapa[c]=-1;
    for(auto c: s3) mapa[c]=-1;
    for(auto x: mapa) letras.eb(x.first);
    solve(0);
    cout<<res<<endl;
    for(auto x:mapa_res) cout<<x.first<<":"<<x.second<<endl;
    return 0;
}