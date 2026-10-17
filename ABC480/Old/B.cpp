#include<iostream>
using namespace std; const int N = 105;
int n,m,h[N]; string s[N],t;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1;i <= n;i++)
    cin >> s[i];
  while (m--){
    cin >> t;
    int maxx,demax;
    for (int k = 1;k <= n;k++){
      if (s[k].size() != t.size()) continue;
      int cnt = 0,len = s[k].size();
      for (int i = 0;i < len;i++)
        cnt += bool(s[k][i] == t[i]);
      if (cnt == len - 1 && demax){
        demax = -1;
        continue;
      }
      if (cnt == len){
        maxx = k;
        break;
      }else if (cnt == len - 1 && demax != -1)
        demax = k;
    }
    if (maxx > 0)
      h[maxx]++;
    else if (demax > 0)
      h[demax]++;
  }
  for (int i = 1;i <= n;i++)
    cout << h[i] << '\n';
  return 0;
}
