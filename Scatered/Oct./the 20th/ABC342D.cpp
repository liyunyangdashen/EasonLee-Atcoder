#include<iostream>
using namespace std; using ll = long long; const int N = 2e5 + 5;  
int n,a[N],p[N],cnt = 0,to[N],h[N]; bool vis[N]; ll ans = 0;
void Euler_Sieve(int x){
  vis[0] = vis[1] = 1; to[0] = 0; to[1] = 1;
  for (int i = 2;i <= x;i++){
    if (!vis[i]) p[++cnt] = i, to[i] = i;
    for (int j = 1;j <= cnt && i * p[j] <= x;j++){ 
      vis[i * p[j]] = 1;
      if (to[i] % p[j] == 0) to[i * p[j]] = to[i] / p[j];
      else to[i * p[j]] = to[i] * p[j];
      if (i % p[j] == 0) break;
    }
  }
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  Euler_Sieve(N - 5);
  cin >> n;
  for (int i = 1;i <= n;i++){
    cin >> a[i];
    a[i] = to[a[i]];
    h[a[i]]++;
  }
  ans += (ll)n * (n - 1) / 2 - (ll)(n - h[0]) * (n - h[0] - 1) / 2;
  for (int i = 1;i <= N - 5;i++)
    ans += (ll)h[i] * (h[i] - 1) / 2;
  cout << ans;
  return 0;
}
