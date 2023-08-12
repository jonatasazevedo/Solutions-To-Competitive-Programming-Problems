#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
typedef long long ll;
#define MAX_N 10005
#define MAX_PEDRAS 1000000000

int palp[MAX_N],vetErros[MAX_N];
set<int> resposta;
map<int,int> erros;
int n;
void solve(int ind,int num){
  if(ind>=n){
    resposta.emplace(num);
    return;
  }
  int erroDesejado = abs(num-palp[ind]);
  if(erros[erroDesejado]>0){
    erros[erroDesejado]--;
    solve(ind+1,num);
    erros[erroDesejado]++;
  }
}

int main(){_
  cin>>n;
  for(int i=0;i<n;i++) cin>>palp[i];
  for(int i=0;i<n;i++){
    int x; cin>>x;
    vetErros[i] = x;
    erros[x]++;
  }
  //testar todos os erros para a primeira pessoa
  int palpite=palp[0];
  for(int i=0;i<n;i++){
    int erroAtual = vetErros[i];
    int num1 = palpite - erroAtual; // P-E = X
    int num2 = palpite + erroAtual; // P+E = X
    erros[erroAtual]--;
    if(num1>=1 && num1<=MAX_PEDRAS) solve(1,num1);
    if(num2>=1 && num2<=MAX_PEDRAS) solve(1,num2);
    erros[erroAtual]++;
  }
  for(auto it=resposta.begin();it!=resposta.end();it++){
    cout<<(*it)<<endl;
  }
}