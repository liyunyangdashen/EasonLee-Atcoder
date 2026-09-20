#include<iostream>
using namespace std; 
int n; string a,b;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a >> b;
  for (int i = 0;i < n;i++)
    if (a[i] != '*' && b[i] != '*' && a[i] != b[i]){
      cout << "No";
      return 0;
    }
  cout << "Yes";
  return 0;
}
