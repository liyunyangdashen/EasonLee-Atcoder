#include<iostream>
using namespace std; const int N = 2e5 + 5;
int n,a[N],b[N],split; bool flagf = 0,flagb = 0,flagc,flagt = 0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1;i <= n;i++)
    cin >> a[i];
  for (int i = 1;i <= n;i++)
    cin >> b[i];
  for (int i = 1;i <= n;i++){
    if (flagf){
      if (flagb){
        if (a[i] != b[i]){
          flagt = 1;
          break;
        }
      }else{
        if (flagc && b[i + 1] != a[i]){
          if (a[i] == b[split])
            flagb = 1;
          else{
            flagt = 1;
            break;
          }
        }else if (!flagc && b[i] != a[i + 1]){
          if (b[i] == a[split])
            flagb = 1;
          else{
            flagt = 1;
            break;
          }
        }
      }
    }else
      if (b[i] != a[i]){
        flagf = 1; split = i;
        if (b[i] == a[i + 1])
          flagc = 0;
        else if (b[i + 1] == a[i])
          flagc = 1;
        else{
          flagt = 1;
          break;
        }
      }
  }
  if (flagt)
    cout << "No";
  else
    cout << "Yes";
  return 0;
}//C_old
