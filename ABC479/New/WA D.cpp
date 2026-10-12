#include<iostream>
#include<cstring>
#include<cmath>
using namespace std; using ll = long long; const int N = 3e5 + 5,INF = 0x3f3f3f3f;
int n,q,s,t; ll lt[N],rt[N],wl[N],wr[N];
void unionn(int x){wl[x] = min(wl[x << 1],wl[x << 1 | 1]); wr[x] = min(wr[x << 1],wr[x << 1 | 1]);}
void build(int x,int l,int r){if (l == r){wl[x] = lt[l]; wr[x] = rt[l]; return ;} int mid = (l + r) >> 1; build(x << 1,l,mid); build(x << 1 | 1,mid + 1,r); unionn(x);}
bool inRange(int L,int R,int l,int r){return l <= L && R <= r;} bool outRange(int L,int R,int l,int r){return r < L || R < l;}
ll getMinl(int x,int l,int r,int fm){if (inRange(l,r,fm + 1,n)) return wl[x]; else if (!outRange(l,r,fm + 1,n)){int mid = (l + r) >> 1; return min(getMinl(x << 1,l,mid,fm),getMinl(x << 1 | 1,mid + 1,r,fm));}else return INF;}
ll getMinr(int x,int l,int r,int fm){if (inRange(l,r,1,fm - 1)) return wr[x]; else if (!outRange(l,r,1,fm - 1)){int mid = (l + r) >> 1; return min(getMinr(x << 1,l,mid,fm),getMinr(x << 1 | 1,mid + 1,r,fm));}else return INF;}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  lt[1] = rt[n] = INF;
  for (int i = 2;i <= n;i++)
    cin >> lt[i];
  for (int i = 1;i < n;i++)
    cin >> rt[i];
  build(1,1,n);
  while (q--){
    cin >> s >> t;
    if (s < t){
      if (lt[s] >= rt[s])
        cout << rt[s];
      else
        cout << lt[s] + getMinr(1,1,n,s);
    }else{
      if (rt[s] >= lt[s])
        cout << lt[s];
      else
        cout << rt[s] + getMinl(1,1,n,s);
    }
    cout << '\n';
  }
  return 0;
}
