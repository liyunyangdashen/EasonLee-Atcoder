#include<iostream>//sort finished,only left & right
using namespace std; const int N = 2e5 + 5; //even numbers 
int n,pos[N];//but use k-1 & k+1 maybe can be better
int main(){//actually it's just left and right
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1;i <= n;i++)
    cin >> pos[i];
  pos[n + 1] = pos[n];
  for (int k = 1;k <= n;k++)
    cout << min(max((pos[k] - pos[1]) / 2,(pos[n] - pos[k - 1]) / 2), 
    max((pos[n] - pos[k]) / 2,(pos[k + 1] - pos[1]) / 2)) << '\n';
  return 0;
}
