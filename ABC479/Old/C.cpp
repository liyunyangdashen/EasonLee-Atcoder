#include<iostream>
using namespace std; using ll = long long; const int N = 25,T = 1e9 + 5;
int n,t,c[N],v[N]; ll ans = 0;
void dfs(int d,ll wt,ll sum){
  if (d > n){
    ans = max(ans,sum);
    return ;
  }
  for (int i = 0;i < 2;i++)
    if (wt + c[d] * i <= t)
      dfs(d + 1,wt + c[d] * i,sum + v[d] * i);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> t;
  for (int i = 1;i <= n;i++)
    cin >> v[i] >> c[i];
  dfs(1,0,0);
  cout << ans;
  return 0;
}
