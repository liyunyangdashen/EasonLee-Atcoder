#include<iostream>//统计row&col,bs,minus
#include<algorithm>//约束=N,H&W诱惑,no顺序,no need to care
using namespace std; const int N = 3e5 + 5; 
int h,w,n,q,r[N],c[N],op,x,y;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> h >> w >> n >> q;
  for (int i = 1;i <= n;i++)
    cin >> r[i] >> c[i];
  sort(r + 1,r + n + 1);
  sort(c + 1,c + n + 1);
  while (q--){
    cin >> op >> x >> y;
    //统计use upper-lower
    if (op == 2)
      cout << upper_bound(c + 1,c + n + 1,y) - lower_bound(c + 1,c + n + 1,x);
    else
      cout << upper_bound(r + 1,r + n + 1,y) - lower_bound(r + 1,r + n + 1,x);
    cout << '\n';
  }
  return 0;
}
