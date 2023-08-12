#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
#define endl '\n';
using namespace std;
typedef long long ll;

#define MAX_NQ 1000005

int a[MAX_NQ];
set<int> numberList;
// int numberList[4*MAX_NQ], qtNumbers=0;
unordered_map<int,int> numberMap;

struct Query{
  int op, x, y;
} queries[MAX_NQ];

#define LSB(x) ((x)&-(x))
ll bit[4*MAX_NQ];

ll sum_pre(int i){ //[1,i]
  ll res=0;
  for(;i>0;i-=LSB(i)) res+=bit[i];
  return res;
}
ll sum_range(int l, int r){ //[l,r]
  return sum_pre(r)-sum_pre(l-1);
}
void add(int i, ll v, int n){
  for(;i<=n;i+=LSB(i)) bit[i]+=v;
}

// multiset<int> collection;

vector<int> collection;

int main(){
  int n, q;
  scanf("%d %d", &n, &q);

  //mapping:
  for(int i=0;i<n;i++){
    scanf("%d", &a[i]);
    numberList.emplace(a[i]);
    // numberList[qtNumbers++] = a[i];
  }

  for(int i=0;i<q;i++){
    scanf("%d %d", &queries[i].op, &queries[i].x);
    numberList.emplace(queries[i].x);
    // numberList[qtNumbers++] = queries[i].x;
    if(queries[i].op==2){
      scanf("%d", &queries[i].y);
      numberList.emplace(queries[i].y);
      // numberList[qtNumbers++] = queries[i].y;
    }
  }

  int qtNumbersUnique=0;
  for(auto it=numberList.begin();it!=numberList.end();it++)
    numberMap[*it]=(++qtNumbersUnique);

  for(int i=0;i<n;i++){
    int v=numberMap[a[i]];
    collection.emplace_back(v);
    add(v, 1, qtNumbersUnique);
  }
  sort(collection.begin(), collection.end());

  for(int i=0;i<q;i++){
    // cout<<q<<endl;
    int x = numberMap[queries[i].x];
    if(queries[i].op==2)
      printf("%lld\n", sum_range(x, numberMap[queries[i].y]));
    else{
      // auto it = collection.lower_bound(x);
      auto it = lower_bound(collection.begin(), collection.end(), x); 
      if(it!=collection.end() && (*it)==x) continue; //already in the collection
      else if(it==collection.end()){
        add(x, 1, qtNumbersUnique);
        collection.emplace_back(x); //greater than all
      }
      else{
        add(*it, -1, qtNumbersUnique);
        add(x, 1, qtNumbersUnique);
        *it = x;
      }
    }
  }

  return 0;
}