#include<iostream>
using namespace std; const int N = 2e5 + 5;
int n,m,l,r,a[N],p[N],wmax[N << 2],wmin[N << 2];
void unionnMin(int x){wmin[x] = min(wmin[x << 1],wmin[x << 1 | 1]);} void unionnMax(int x){wmax[x] = max(wmax[x << 1],wmax[x << 1 | 1]);} void unionn(int x){unionnMin(x); unionnMax(x);}
void build(int x,int l,int r){if (l == r){wmin[x] = wmax[x] = a[l]; return ;} int mid = (l + r) >> 1; build(x << 1,l,mid); build(x << 1 | 1,mid + 1,r); unionn(x);}
bool inRange(int L,int R,int l,int r){return l <= L && R <= r;} bool outRange(int L,int R,int l,int r){return R < l || L > r;}
void update(int x,int l,int r,int pos,int val){if (pos == l && l == r){wmin[x] = wmax[x] = val; return ;}int mid = (l + r) >> 1; if (pos <= mid) update(x << 1,l,mid,pos,val); else update(x << 1 | 1,mid + 1,r,pos,val); unionn(x);}
int getMin(int x,int L,int R,int l,int r){if (inRange(L,R,l,r)) return wmin[x]; else if (!outRange(L,R,l,r)){int mid = (L + R) >> 1; return min(getMin(x << 1,L,mid,l,r),getMin(x << 1 | 1,mid + 1,R,l,r));}else return 1e9;}
int getMax(int x,int L,int R,int l,int r){if (inRange(L,R,l,r)) return wmax[x]; else if (!outRange(L,R,l,r)){int mid = (L + R) >> 1; return max(getMax(x << 1,L,mid,l,r),getMax(x << 1 | 1,mid + 1,R,l,r));}else return -1e9;}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1;i <= n;i++){
    cin >> a[i]; p[a[i]] = i;}
  build(1,1,n);
  while (m--){
    cin >> l >> r;
    int minn = getMin(1,1,n,l,r),maxx = getMax(1,1,n,l,r),mini = p[minn],maxi = p[maxx];
    swap(a[mini],a[maxi]);
    swap(p[minn],p[maxx]);
    update(1,1,n,mini,maxx);
    update(1,1,n,maxi,minn);
  }
  for (int i = 1;i <= n;i++)
    cout << a[i] << ' ';
  return 0; 
}
*/
#include<iostream>
using namespace std; 
string s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  cout << s;
  if (s[s.size() - 1] != 'e') cout << 'e';
  cout << 'r';
  return 0;
}
