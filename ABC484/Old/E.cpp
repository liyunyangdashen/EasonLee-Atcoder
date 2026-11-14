#include<iostream>
#include<algorithm>
using namespace std; using ll = long long; const int N = 3e5 + 5;
int n,m,tr[N * 3]; ll l,r,a[N],s[N],b[N * 3],ans;
int lowbit(int x){return x & -x;}
void add(int x,int v){while (x <= m){tr[x] += v; x += lowbit(x);}}
int query(int x){int res = 0; while (x > 0){res += tr[x]; x -= lowbit(x);} return res;}
int getid(ll x){return lower_bound(b + 1,b + m + 1,x) - b;}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> l >> r;
  b[++m] = 0;
  for (int i = 1;i <= n;i++){
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    b[++m] = s[i];
    b[++m] = s[i] - l;
    b[++m] = s[i] - r;
  }
  sort(b + 1,b + m + 1);
  m = unique(b + 1,b + m + 1) - (b + 1);
  add(getid(0),1);
  for (int i = 1;i <= n;i++){
    int ql = getid(s[i] - r);
    int qr = getid(s[i] - l);
    ans += query(qr) - query(ql - 1);
    add(getid(s[i]),1);
  }
  cout << ans;
  return 0;
}//E
