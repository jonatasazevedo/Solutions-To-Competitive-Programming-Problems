#include<bits/stdc++.h>

using namespace std;

#include<bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ost;

typedef long long int ll;
typedef pair<ll,ll> pii;

const ll MAX_N = 100010;

struct SegTree{
  pii values[2*MAX_N+5];
  ll n, nx;

  pii NEUTRAL_ELEMENT = {-1,-1};

  pii single(ll v,int pos){return {v,pos};}
  pii merge(pii l, pii r){
    return max(l,r);
  }

  void build(ll *a, ll x, ll lx, ll rx){
    if(lx == rx) {values[x] = single(a[lx], lx); return;}
    ll mid = (lx+rx)/2, x1=x+1, x2=x+2*(mid-lx+1);

    build(a,x1,lx,mid); build(a,x2, mid+1, rx);

    values[x] = merge(values[x1], values[x2]);
  }

  void build(ll *a, ll n){
    this->n=n; nx=2*n-1;
    build(a,0,0,n-1);
  }

  void update_set(ll i, ll v, ll x, ll lx, ll rx){
    if(lx == rx){values[x] = single(v,lx); return;}

    ll mid = (lx+rx)/2, x1 = x+1, x2=x+2*(mid-lx+1);
    if(i <= mid) update_set(i,v,x1,lx,mid);
    else update_set(i, v, x2, mid+1, rx);

    values[x] = merge(values[x1], values[x2]);
  }

  void update_set(ll i, ll v){
    update_set(i,v,0,0,n-1);
  }

  pii rmq(ll l, ll r, ll x, ll lx, ll rx){
    if(rx < l || r < lx) return NEUTRAL_ELEMENT;
    if(l<=lx && rx<=r) return values[x];

    ll mid = (lx+rx)/2, x1 = x+1, x2= x+2*(mid-lx+1);
    pii v1 = rmq(l,r,x1,lx, mid);
    pii v2 = rmq(l,r,x2,mid+1, rx);

    return merge(v1,v2);
  }

  pii rmq(ll l, ll r){
    return rmq(l,r,0,0,n-1);
  }
};

ll op,n,q,x,b[MAX_N],a[MAX_N];
ll l,r,p;

void tiraST(SegTree &st, map<int,ost> &s, int p){
  
  int sucessor = (s[a[p]].order_of_key(p)) +1;

  if(sucessor < s[a[p]].size()){
    sucessor = *s[a[p]].find_by_order(sucessor);
    b[sucessor] = b[p];
    st.update_set(sucessor,b[p]);
  }
  s[a[p]].erase(p);
  
  b[p] = -1;
  st.update_set(p,-1);
}

void adicionaST(SegTree &st, map<int,ost> &s, int p, int x){
  int n_sucessor = (s[x].order_of_key(p));
  //cout << n_sucessor << "\n";
  if(s[x].size() == 0){
    b[p] = -1;
    st.update_set(p,-1);
  }else if(n_sucessor < s[x].size()){ 
    n_sucessor = *s[x].find_by_order(n_sucessor);
    //cout << n_sucessor << "\n";
    b[p] = b[n_sucessor];
    st.update_set(p,b[n_sucessor]);
    b[n_sucessor] = p;
    st.update_set(n_sucessor,p);
  }else{
    int n_pre = n_sucessor -1;
    if(n_pre >= 0){
      n_pre = *s[x].find_by_order(n_pre);
      b[p] = n_pre;
      st.update_set(p,n_pre);
    }
  }
  s[x].insert(p);
}


int main(){

   cin >> n >> q;
  memset(b,-1,sizeof(b));  

  map<int,int> last_appear;
  map<int,ost> s;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(last_appear.count(a[i]) != 0) b[i] = last_appear[a[i]];
    last_appear[a[i]] = i;

    s[a[i]].insert(i);
  }

  SegTree st;
  st.build(b,n);
  
  for(int i=0;i<q;i++){

    cin >> op;

    if(op == 1){
      cin >> l >> r;
      l--;r--;
      pii meu = st.rmq(l,r);

      pii aux = {b[meu.first],b[meu.second]};
      
      tiraST(st, s,meu.second);
      tiraST(st, s,meu.first);
   

      pii uchoa = st.rmq(l,r);
      adicionaST(st, s, meu.second,a[meu.second]);
      adicionaST(st, s, meu.first,a[meu.first]);

      if(meu.first != -1 && uchoa.first != -1 && meu.first >= l && uchoa.first >= l){
        cout << (meu.first+1) << " " << (meu.second+1) << " " <<
          (uchoa.first+1) << " " << (uchoa.second+1) << "\n";
      }else{
        cout << -1 << "\n";
      }
    }else{
      cin >> p >> x;
      p--;  

      tiraST(st, s,p);
      
      a[p] = x;
      adicionaST(st, s, p,a[p]);  
    } 
  }
}