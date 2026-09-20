#include<iostream>
using namespace std; const int N = 5e5 + 5;
int n,a[N];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int maxx = -1e9,demax = -1e9,pemax = -1e9;
  for (int i = 1;i <= n;i++){
    cin >> a[i];
    if (a[i] >= maxx) pemax = demax,demax = maxx,maxx = a[i];
    else if (a[i] >= demax) pemax = demax,demax = a[i];
    else if (a[i] > pemax) pemax = a[i];
    if (i >= 3) cout << pemax << ' ';
  }
  return 0;
}
