#include<iostream>
using namespace std; const int N = 2e5 + 5;
int n,a[N],b[N],l = 1,r; bool ok1,ok2;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n; r = n;
  for (int i = 1;i <= n;i++)
    cin >> a[i];
  for (int i = 1;i <= n;i++)
    cin >> b[i];
  while (l <= n && a[l] == b[l])
    l++;
  if (l > n){
    cout << "Yes";
    return 0;
  }
  while (r >= 1 && a[r] == b[r])
    r--;
  ok1 = (a[l] == b[r]);
  ok2 = (a[r] == b[l]);
  for (int i = l;i < r;i++){
    if (a[i + 1] != b[i])
      ok1 = 0;
    if (a[i] != b[i + 1])
      ok2 = 0;
  }
  if (ok1 || ok2)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}//C_acc
