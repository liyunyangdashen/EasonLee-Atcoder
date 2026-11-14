#include<iostream>
using namespace std; 
int n,x,minn = 10; bool flag;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1;i <= n;i++){
    cin >> x;
    minn = min(x,minn);
    if (x == 9) flag = 1;
  }
  if (!flag) cout << -1;
  else cout << minn;
  return 0;
}
