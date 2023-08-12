#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
using namespace std;
 
typedef long long int ll; 
typedef pair<ll,ll> pii;
typedef vector<int> vi;
 
const int MAX_N = 500010;
const ll M = 1e15;

struct node{
  ll mx,mi,dd;
  pii ddp;
};

ll p[MAX_N];

struct SegTree{
  ll size, nx;
  vector<node> values;

  node NEUTRAL_ELEMENT={
    INT64_MIN,INT64_MAX,INT64_MIN,{0,M}
  };

  void init(int n){
		size = 1;
		while(size < n) size *= 2;
		values.resize(2*size,NEUTRAL_ELEMENT);
	}


  node single(ll v){ 

    if(v == 0){
      return NEUTRAL_ELEMENT;
    }

    return {
      v,v,0,{0,M}
    }; 
  } 
  node unite(node v, node w){ 

    ll cand_dd = max(v.dd,w.dd);
    if(v.mx != INT64_MIN && w.mi != INT64_MAX) cand_dd = max(cand_dd,max(0LL,v.mx - w.mi));

    pii cand_ddp;
    
    if(w.ddp.second == M){
      cand_ddp = v.ddp;
    }else if(v.ddp.second == M){
      cand_ddp = w.ddp;
    }else if(v.ddp.first*w.ddp.second > v.ddp.second*w.ddp.first){
      cand_ddp = v.ddp;
    }else{
      cand_ddp = w.ddp;
    }

    if(v.mx != INT64_MIN && w.mi != INT64_MAX){
      pii possible = {max(0LL,v.mx - w.mi),v.mx};     
      if((cand_ddp.second == M) || (possible.first*cand_ddp.second > possible.second*cand_ddp.first)){
        cand_ddp = possible;
      }
    }

    ll gcd = __gcd(cand_ddp.first, cand_ddp.second);
    
    cand_ddp = {cand_ddp.first/gcd, cand_ddp.second/gcd};

    return {
      max(v.mx,w.mx), min(v.mi,w.mi),
      cand_dd, cand_ddp
    };
  }

  void build(ll *a, ll x, ll lx, ll rx){
    if(lx==rx){values[x]=single(a[lx]); return;}
    ll mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);
    build(a, x1, lx, mid); build(a, x2, mid+1, rx);
    values[x]=unite(values[x1], values[x2]);
  }
  void build(ll *a){
    //cout << "top\n";
    nx=2*size-1;
    build(a, 0, 0, size-1);
  }

  node query_sum(ll l, ll r, ll x, ll lx, ll rx){
    if(rx<l || r<lx) return NEUTRAL_ELEMENT;
    if(l<=lx && rx<=r) return values[x];
    ll mid=(lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);
    node v1=query_sum(l, r, x1, lx, mid), v2=query_sum(l, r, x2, mid+1, rx);
    return unite(v1, v2);
  }
  node query_sum(ll l, ll r){
    return query_sum(l, r, 0, 0, size-1);
  }
};


int n,q,l,r;

int main(){ _

    cin >> n;

    for(int i=0;i<n;i++){
      cin >> p[i];
    }  

    SegTree st;
    st.init(n);
    st.build(p);

 
  cin >> q;
  while(q--){
    cin >> l >> r;

    l--,r--;

    node ans = st.query_sum(l,r);


    ll gcd = __gcd(ans.ddp.first, ans.ddp.second);
    cout << ans.dd <<  " " 
    << (ans.ddp.first/gcd) << " "
    << (ans.ddp.second/gcd) << "\n"; 
  }


}
 
 