#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<int> vi;

#define MAX_N 100005

ll in[MAX_N], out[MAX_N];

struct Node{
  ll mxIn, mxOut, ans;
  Node(){
    mxIn = mxOut = ans = 0;
  }
  Node(ll x){
    mxIn=mxOut=ans=x;
  }
};

//RSQ e update_set - (podem ser alterados)
struct SegTree{
  Node values[2*MAX_N+5];
  ll n, nx;

  Node unite(Node &u, Node &v){
    Node aux;

    aux.mxIn = max(u.mxIn, v.mxIn);
    aux.mxOut = max(u.mxOut, v.mxOut);
    aux.ans = max({
      u.ans, v.ans,
      u.mxIn  + v.mxOut, // u->v
      u.mxOut + v.mxIn   // v->u
    });

    return aux;
  }

  void build(ll n){
    this->n=n; nx=2*n-1;
  }

  void update_add(ll i, bool plusIn, ll x, ll lx, ll rx){
    if(lx==rx){
      if(plusIn) values[x].mxIn++;
      else values[x].mxOut++;
      values[x].ans = values[x].mxIn + values[x].mxOut + 1;
      return;
    }
    ll mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);
    if(i<=mid) update_add(i, plusIn, x1, lx, mid);
    else update_add(i, plusIn, x2, mid+1, rx);
    values[x]=unite(values[x1], values[x2]);
  }
  void update_add(ll i, bool plusIn){
    update_add(i, plusIn, 0, 0, n-1);
  }

  Node query(ll l, ll r, ll x, ll lx, ll rx){
    if(rx<l || r<lx) return Node(INT_MIN);
    if(l<=lx && rx<=r) return values[x];
    ll mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);
    Node v1=query(l, r, x1, lx, mid), v2=query(l, r, x2, mid+1, rx);
    return unite(v1, v2);
  }
  Node query(ll l, ll r){
    return query(l, r, 0, 0, n-1);
  }
} seg;

int main(){_
  ll n, t, u, v;
  cin>>n>>t;
  seg.build(n);

  ll ans=0;
  while(t--){
    cin>>u>>v;
    out[u]++; in[v]++;
    ans += in[u]+out[v];
    if(u==v) ans--;
    seg.update_add(u-1, false); //out u
    seg.update_add(v-1, true);  //in  v
    cout<<ans<<" "<<seg.query(0,n-1).ans<<endl;
  }

  return 0;
}