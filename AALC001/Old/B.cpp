#include<iostream>
using namespace std; using ll = long long; const int N = 2e5 + 5;
int n,q,a[N],op,l,r; ll x,w[N << 2],lzt[N << 2];
void unionn(int x){w[x] = min(w[x << 1],w[x << 1 | 1]);}
void build(int x,int l,int r){if (l == r){w[x] = a[l]; return ;}int mid = (l + r) >> 1; build(x << 1,l,mid); build(x << 1 | 1,mid + 1,r); unionn(x);}
void apply(int x,int len,ll val){lzt[x] += val; w[x] += val;}
void pushup(int x,int l,int r){int mid = (l + r) >> 1; apply(x << 1,mid - l + 1,lzt[x]); apply(x << 1 | 1,r - mid,lzt[x]); lzt[x] = 0;}
bool inRange(int L,int R,int l,int r){return l <= L && R <= r;} bool outRange(int L,int R,int l,int r){return r < L || R < l;}
void update(int x,int l,int r,int posl,int posr,ll val){if (inRange(l,r,posl,posr)) apply(x,r - l + 1,val); else if (!outRange(l,r,posl,posr)){int mid = (l + r) >> 1; pushup(x,l,r); update(x << 1,l,mid,posl,posr,val); update(x << 1 | 1,mid + 1,r,posl,posr,val); unionn(x);}}
ll getMin(int x,int L,int R,int l,int r){if (inRange(L,R,l,r)) return w[x]; else if (!outRange(L,R,l,r)){pushup(x,L,R); int mid = (L + R) >> 1; return min(getMin(x << 1,L,mid,l,r),getMin(x << 1 | 1,mid + 1,R,l,r));}else return 2e18;}
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
    if (op - 2){
      cin >> x;
      update(1,1,n,l,r,x);
    }else
      cout << getMin(1,1,n,l,r) << '\n';
  }
  return 0;
}
