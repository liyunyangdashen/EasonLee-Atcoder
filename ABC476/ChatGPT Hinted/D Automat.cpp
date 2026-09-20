#include<iostream>
#include<algorithm>
using namespace std; using ll = long long; const int N = 2e5 + 5; 
ll n,m,k,x,y,a[N],b[N],pa[N],pb[N],nd[N]; int ans = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k >> x >> y;
  for (int i = 1;i <= n;i++)
    cin >> a[i];
  for (int i = 1;i <= m;i++)
    cin >> b[i];
  sort(a + 1,a + n + 1);
  sort(b + 1,b + m + 1);
  for (int i = 1;i <= n;i++)
    pa[i] = pa[i - 1] + a[i];
  for (int i = 1;i <= m;i++)
    pb[i] = pb[i - 1] + b[i],
    nd[i] = nd[i - 1] + (b[i] + k - 1) / k;
  ll money = x + y * k;
  int j = upper_bound(pa,pa + n + 1,money) - pa - 1;
  ans = j;
  for (int i = 1;i <= m;i++){
    if (nd[i] > y) break;
    while (j && pa[j] > money - pb[i]) j--;
    ans = max(ans,i + j);
  }
  cout << ans;
  return 0;
}
