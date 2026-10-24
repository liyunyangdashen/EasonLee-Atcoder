#include<iostream>
#include<stack>
using namespace std; const int N = 2e5 + 5;
int n,a[N],ans[N]; stack<int> s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1;i <= n;i++)
    cin >> a[i];
  for (int i = n;i >= 1;i--){
    ans[i] = s.size();
    while (!s.empty() && a[s.top()] < a[i])
      s.pop();
    s.push(i);
  }
  for (int i = 1;i <= n;i++)
    cout << ans[i] << ' ';
  return 0;
}
