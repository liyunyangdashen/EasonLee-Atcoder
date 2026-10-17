#include<iostream>
using namespace std; 
char c[2][2];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> c[0][0] >> c[0][1] >> c[1][0] >> c[1][1];
  for (int i = 0;i < 2;i++)
    for (int j = 0;j < 2;j++){
      if (c[i][j] == 'A' && (c[!i][j] == 'D' || c[i][!j] == 'D')){
        cout << "Yes";
        return 0;
      }else if (c[i][j] == 'D' && (c[!i][j] == 'A' || c[i][!j] == 'A')){
        cout << "Yes";
        return 0;
      }
    }
  cout << "No";
  return 0;
}
