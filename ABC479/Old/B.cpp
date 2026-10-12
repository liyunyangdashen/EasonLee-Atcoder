#include<iostream>
using namespace std; 
int n,cnt = 0,ans = 0; char c; bool b;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1;i <= n;i++){
    cin >> c; b = (c == 'R');
    if (b) cnt++;
    else ans = max(ans,cnt), cnt = 0;
  }
  ans = max(ans,cnt);
  cout << ans;
  return 0;
}
