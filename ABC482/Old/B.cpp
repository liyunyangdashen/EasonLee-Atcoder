#include<iostream>
using namespace std; const int N = 5;
string s[N]; int ans = 5;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0;i < N;i++)
    cin >> s[i];
  for (int k = 0;k < N;k++){
    int cnt = 0;
    for (int i = 0;i < N;i++)
      cnt += (s[k][i] != 'o');
      ans = min(ans,cnt);
    cnt = 0;
    for (int j = 0;j < N;j++)
      cnt += (s[j][k] != 'o');
    ans = min(ans,cnt);
  }
  int cnt = 0;
  for (int k = 0;k < N;k++)
    cnt += (s[k][k] != 'o');
  ans = min(ans,cnt);
  cnt = 0;
  for (int k = 0;k < N;k++)
    cnt += (s[k][N - k] != 'o');
  ans = min(ans,cnt);
  cout << ans;
  return 0;
}
