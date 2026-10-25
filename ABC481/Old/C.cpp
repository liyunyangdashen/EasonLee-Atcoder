#include<iostream>
#include<map>
using namespace std; const int N = 105;
int q,least = 1; string s; map<string,int> mp;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  while (q--){
    cin >> s;
    if (!mp[s]){
      mp[s] = least;
      least++;
    }
    cout << mp[s] << '\n';
  }
  return 0;
}
