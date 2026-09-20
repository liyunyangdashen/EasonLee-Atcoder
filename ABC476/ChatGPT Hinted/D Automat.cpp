#include<iostream>
#include<cmath>
using namespace std; using ll = long long; const int N = 1505; 
ll n,m,a[N],b[N],t[N][N],c[N][N],ans = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1;i <= n;i++)
    cin >> a[i];
  for (int i = 1;i <= n;i++)
    cin >> b[i];
  for (int i = 1;i <= n;i++)
    for (int j = 1;j <= n;j++)
      t[i][j] = a[i] * b[j] % m;
  for (int i = 1;i <= n;i++)
    for (int j = 1;j <= n;j++)
      for (int k = 1;k <= n;k++)
        if (c[i][j] == 0)
          cout << c[i][k] << ' ';
  return 0; 
}
