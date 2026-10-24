#include<iostream>
#include<stack>
using namespace std; const int N = 2e5 + 5;
int n,a[N],ans[N],asn[N]; stack<int> smax,smin;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1;i <= n;i++)
    cin >> a[i];
  for (int i = n;i >= 1;i--){
    while (!smin.empty() && a[smin.top()] > a[i])
      smin.pop();
    while (!smax.empty() && a[smax.top()] < a[i])
      smax.pop();
    if (!smin.empty())
      ans[i] = asn[smin.top()] + 1;
    if (!smax.empty())
      asn[i] = asn[smax.top()] + 1;
    smin.push(i);
    smax.push(i);
  }
  for (int i = 1;i <= n;i++)
    cout << ans[i] << ',' << asn[i] << ' ';
  return 0;
}
