#include<iostream>
using namespace std; const int N = 2e5 + 5;
int n,q,a[N],op,l,r,w[N << 2];
void unionn(int x){w[x] = min(w[x << 1],w[x << 1 | 1]);}
void build(int x,int l,int r){if (l == r){w[x] = a[l]; return ;}int mid = (l + r) >> 1; build(x << 1,l,mid); build(x << 1 | 1,mid + 1,r); unionn(x);}
bool inRange(int L,int R,int l,int r){return l <= L && R <= r;} bool outRange(int L,int R,int l,int r){return r < L || R < l;}
void update(int x,int l,int r,int pos,int val){if (l == pos && l == r){w[x] = val; return ;}int mid = (l + r) >> 1; if (pos <= mid) update(x << 1,l,mid,pos,val); else update(x << 1 | 1,mid + 1,r,pos,val); unionn(x);}
int getMin(int x,int L,int R,int l,int r){if (inRange(L,R,l,r)) return w[x]; else if (!outRange(L,R,l,r)){int mid = (L + R) >> 1; return min(getMin(x << 1,L,mid,l,r),getMin(x << 1 | 1,mid + 1,R,l,r));}else return 2e9;}
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
      cout << getMin(1,1,n,l,r) << '\n';
  }
  return 0;
}
