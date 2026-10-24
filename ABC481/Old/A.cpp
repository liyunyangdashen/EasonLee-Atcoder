#include<iostream>
using namespace std; 
int a,b;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b;
  if (a + b / 10)
    cout << 2;
  else
    cout << 1;
  return 0;
}
