#include<iostream>
#include<algorithm>
#include<utility>
using namespace std; using ll = long long; using pii = pair<int,int>; const int N = 2e5 + 5;
bool is_upper(const pii& p){return p.first > 0 || (p.first == 0 && p.second >= 0);}
bool cmp(const pii& A,const pii& B){return ((ll)A.first * B.second - (ll)B.first * A.second) < 0;}
bool comp(const pii& A,const pii& B){if (is_upper(A) != is_upper(B)) return is_upper(A); return cmp(A,B);}
int t,n,ans; pii ps[N * 2]; 
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--){
    ans = 1;
    cin >> n;
    for (int i = 1;i <= n;i++)
      cin >> ps[i].first >> ps[i].second;
    sort(ps + 1,ps + n + 1,comp);
    for (int i = 1;i <= n;i++)
      ps[i + n] = ps[i]; 
    int r = 0;
    for (int l = 1;l <= n;l++){
      r = max(l + 1,r);
      while (r <= l + n && cmp(ps[l],ps[r]))
        r++;
      ans = max(ans,r - l);
    }
    cout << ans << '\n';
  }
  return 0;
}
