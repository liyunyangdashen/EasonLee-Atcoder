#include<iostream>
using namespace std; 
int a,b,s = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b;
  a += b;
  while (a){
    s++;
    a /= 10;
  }
  cout << s;
  return 0;
}
