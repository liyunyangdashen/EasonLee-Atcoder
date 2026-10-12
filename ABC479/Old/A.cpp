#include<iostream>
using namespace std; 
int n,x,sum = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1;i <= n;i++){
    cin >> x;
    sum += x * (i % 2);
  }
  cout << sum;
  return 0;
}
