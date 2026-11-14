#include<iostream>
using namespace std; using ll = long long; const int N = 1e6 + 5;
int n,q,a[N],op,l,r; ll w[N << 2];
ll unionnn(ll a,ll b){return (a == b ? a : (a == -1 ? b : (b == -1 ? a : -2)));}void unionn(int x){w[x] = unionnn(w[x << 1],w[x << 1 | 1]);}
void build(int x,int l,int r){if (l == r){w[x] = a[l]; return ;} int mid = (l + r) >> 1; build(x << 1,l,mid); build(x << 1 | 1,mid + 1,r); unionn(x);}
void update(int x,int l,int r,int pos,ll val){if (l == r){if (pos == l) w[x] = val; return ;} int mid = (l + r) >> 1; if (pos <= mid) update(x << 1,l,mid,pos,val); else update(x << 1 | 1,mid + 1,r,pos,val); unionn(x);}
bool inRange(int L,int R,int l,int r){return l <= L && R <= r;} bool outRange(int L,int R,int l,int r){return r < L || R < l;}
ll getSame(int x,int L,int R,int l,int r){if (l > r || outRange(L,R,l,r)) return -1; if (inRange(L,R,l,r)) return w[x]; int mid = (L + R) >> 1; return unionnn(getSame(x << 1,L,mid,l,r),getSame(x << 1 | 1,mid + 1,R,l,r));}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (int i = 1;i <= n;i++)
    cin >> a[i];
  build(1,1,n);
  while (q--){
    cin >> op >> l >> r;
    if (op - 2)
      update(1,1,n,l,r);
    else
      if (getSame(1,1,n,l,r) != -2)
        cout << "Yes\n";
      else
        cout << "No\n";
  }
  return 0;
}//F
