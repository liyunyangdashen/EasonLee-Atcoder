#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std; const int N = 2e5 + 5;
int n,k,t,a[N],x,lst,ans = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> t;
  lst = 0;
  for (int i = 1;i <= n;i++)
    cin >> a[i];
  sort(a + 1,a + n + 1);
  for (int i = 1;i <= n;i++){
    x = a[i];
    if (lst >= t) break;
    if (lst < x){
      int pd = ceil((x - lst) * 1.0 / k);
      ans += pd;
      lst = max(x + k,lst + pd * k);
    }else
      lst = x + k;
  }
  if (lst < t)
  ans += ceil((t - lst) * 1.0 / k);
  lst = t;
  cout << ans;
  return 0;
}
