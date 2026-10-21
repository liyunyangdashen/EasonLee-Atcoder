#include<iostream>
using namespace std; using ll = long long; const int N = 2e5 + 5,M = 1e6 + 5;
int n,m,h[M]; ll s[N * 2],ans = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1;i <= n;i++){
    cin >> s[i];
    s[i] = (s[i] + s[i - 1]) % m;
    h[s[i]]++;
  }
  h[s[n]]--;
  for (int i = 1;i <= n;i++)
    s[i + n] = (s[i] + s[n]) % m;
  for (int i = 1;i <= n;i++){
    ans += h[s[i - 1]];
    h[s[i]]--;
    h[s[i + n - 1]]++;//this one
  }
  cout << ans;
  return 0;
}
