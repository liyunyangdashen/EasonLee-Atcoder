#include<iostream>
using namespace std; const int N = 105;
int n,k,a[N],ans = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1;i <= n;i++){
    cin >> a[i];
    if (a[i] == k) ans++;
    if (i > 1)
      if (a[i] > k && a[i - 1] < k || a[i] < k && a[i - 1] > k)
        ans++;
  }
  cout << ans;
  return 0;
}
