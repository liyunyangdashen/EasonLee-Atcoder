#include<iostream>
using namespace std; 
string s; int cnt = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for (int i = 0;i < s.size();i++)
    cnt += (s[i] == 'o');
  if (cnt % 2) cout << "odd";
  else cout << "even";
  return 0;
}
