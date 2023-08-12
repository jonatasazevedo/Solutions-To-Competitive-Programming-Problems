#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using namespace std;

typedef long long int ll;

#define MAX_N 5005

// //1_>jane, 0->John
// int dp[MAX_N][MAX_N];

// //round, remaining
// int solve(int v, int chips){
//   if(chips<=v) return (v&1);
//   if(dp[v][chips]!=-1) return dp[v][chips];

//   for(int i=1;i<=v;i++) //O(5000)
//     if(solve(v+1,chips-i)==(v&1)) return dp[v][chips]=(v&1);

//   return dp[v][chips]=(v&1)?0:1;
// }

int main(){_
  int n; cin>>n;

  if(n==1){cout<<"Jane\n";}
  else{
    n--; //removing 1;
    int i;
    for(i=2;i*2<n;i++) n-=i*2;
    cout<<(n<=i ? "John" : "Jane")<<endl;
  }

  return 0;
}