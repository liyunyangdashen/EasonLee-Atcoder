#include<iostream>// X_1 < X_2 < ... < X_N holds. farest time is only need
using namespace std; const int N = 2e5 + 5; //also,X_i is even,X_a - X_b / 2 is intenger
int n,pos[N],l[N],r[N];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1;i <= n;i++)
    cin >> pos[i];
  int lp = 1;
  for (int i = 1;i <= n;i++){
    while (lp < i && (pos[i] - pos[lp]) > (pos[n] - pos[i]))
      lp++;
    l[i] = (pos[n] - pos[lp]) / 2 + (pos[i] - pos[lp]);
    if (lp > 1)
      l[i] = max(l[i],(pos[n] - pos[lp - 1]) / 2);
  }
  int rp = n;
  for (int i = n;i >= 1;i--){
    while (rp > i && (pos[rp] - pos[i]) > (pos[i] - pos[1]))
      rp--;
    r[i] = (pos[rp] - pos[1]) / 2 + (pos[rp] - pos[i]);
    if (rp < n)
      r[i] = max(r[i], (pos[rp + 1] - pos[1]) / 2);
  }
  for (int k = 1;k <= n;k++)
    cout << max(l[k], r[k]) << '\n';
  return 0;
}
