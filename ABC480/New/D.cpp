#include<iostream>
#include<algorithm>
using namespace std; using ll = long long; const int N = 1e5 + 5;
int n,m; ll s[N],ss[N],pos[N],l,r,p,q,k1,k2;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1;i <= n;i++){
    cin >> s[i];
    s[i] += s[i - 1];
    ss[i] = s[i] + ss[i - 1];
    pos[i] = pos[i - 1] + i;
  }
  while (m--){
    cin >> l >> r;
    q = lower_bound(pos + 1,pos + n + 1,l) - pos, k1 = l - (q - 1) * q / 2;
    p = upper_bound(pos + 1,pos + n + 1,r) - pos - 1, k2 = r - p * (p + 1) / 2;
    cout << ss[p] - ss[q - 1] + s[k2] - s[k1 - 1] << '\n';
  }
  return 0;
}
//分块+前缀和
