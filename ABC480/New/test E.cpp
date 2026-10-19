#include<iostream>
using namespace std; 
__int128_t fac_of_1e18 = 1; int ans = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  while (fac_of_1e18 <= 1e18)
    ans++,
    fac_of_1e18 *= ans;
  cout << ans - 1;
  return 0;
}
