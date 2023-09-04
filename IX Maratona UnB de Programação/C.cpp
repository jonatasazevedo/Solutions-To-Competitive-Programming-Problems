#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int MAX_N = 100005;

ll p;
int a,n;
map<ll, map<int,int, greater<int>>> m;

int isNumber(string word){
  for(char c: word){
    if(c < '0' || c > '9') return 0;
  }

  return 1;
}

int ord(pii a, pii b){
  if(a.first == b.first){
    return a.second < b.second;
  }else{
    return a.first > b.first;
  }
}


int main(){_
  ll n;
  cin>> n;



  for(int i=0;i<n;i++){
    cin >> p >> a;
    m[p][a]++;
  }

  cin.ignore(1000, endl);

  string fala;
  getline(cin, fala); //
  
  //cout << fala << "\n";

  istringstream ss(fala);
  string word;

  int k;
  while(ss >> word){
    if(isNumber(word)){
      k = stoi(word);
      break;
    }
  }

  //cout << k << "\n";

  getline(cin, fala); //

  //cout << fala << "\n";

  ll top;
  for(int i=0;i<k;i++){
    cin >> top;

    if(m.count(top) == 0){
      cout << "Grato, cidadao " << top << ".\n";
    }else{
      cout << "Teje preso, " << top << "!\n";

      vector<pii> ans;

      for(auto it: m[top]){

        ans.push_back({it.second, it.first});
        //
      }

      sort(ans.begin(),ans.end(),ord);

      for(pii it: ans){
        cout << "- Art. " << it.second << ": " << it.first << " ocorrencia(s).\n"; 
      }
    }
  }
  


  return 0;
}