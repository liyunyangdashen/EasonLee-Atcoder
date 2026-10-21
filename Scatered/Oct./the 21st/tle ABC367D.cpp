#include<iostream>
using namespace std; using ll = long long; const int N = 2e5 + 5;
int n,m; ll s[N * 2],ans = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1;i <= n;i++){
    cin >> s[i];
    s[i + n] = s[i] += s[i - 1];
  }
  for (int i = 1;i <= n;i++)
    s[i + n] += s[n];
  for (int i = 1;i <= n;i++)
    for (int len = 2;len <= n;len++){
      int j = i + len - 1;
      if ((s[j - 1] - s[i - 1]) % m == 0)
        ans++;
    }
  cout << ans;
  return 0;
}
